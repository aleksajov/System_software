#include"../inc/linker.hpp"
#include<iostream>
#include<fstream>
#include<cstring>
#include<string>
#include<regex>
#include<cmath>
#include<iomanip>

int main(int argc, char** argv){
    
    Linker& linker=Linker::getInstance();

    if(linker.parseCallingArguments(argc, argv)!=0) return 1;

    
    for(auto& inputFile: linker.getInputFileNames())
    {
        if(linker.readFromBinFile(inputFile)!=0) return 1;
    }

    int stat=linker.placeSections();
    if(stat!=0) return stat;

    stat=linker.checkForUndefinedSymbols();
    if(stat!=0) return stat;

    linker.relocationEntriesResolve();

    linker.makeExecutableFile();
    return 0;
}


int Linker::readFromBinFile(std::string file)
{
    std::ifstream in(file, std::ios::binary);
    if(!in)
    {
        std::cout<<"Error opening file "<<file<<std::endl;
        return 1;
    }

    size_t symbolTableSize;
    in.read(reinterpret_cast<char*>(&symbolTableSize), sizeof(size_t));

    for (size_t i = 0; i < symbolTableSize; i++)
    {
        std::string symName;
        unsigned int symValue;
        std::string symSection;
        bool isGlobal;
        bool isDefined;

        size_t readStringSize;
        in.read(reinterpret_cast<char*>(&readStringSize), sizeof(size_t));
        
        symName.resize(readStringSize);
        in.read(&symName[0], readStringSize);
        in.read(reinterpret_cast<char*>(&symValue), sizeof(unsigned int));
        in.read(reinterpret_cast<char*>(&readStringSize), sizeof(size_t));
        symSection.resize(readStringSize);
        in.read(&symSection[0], readStringSize);
        in.read(reinterpret_cast<char*>(&isGlobal), sizeof(bool));
        in.read(reinterpret_cast<char*>(&isDefined), sizeof(bool));

        if(find(symbolTable.begin(), symbolTable.end(), symName)==symbolTable.end())
        {
            if(symSection!="/" && symSection!="UND")
            {
                unsigned int currSectionSize=sections[symSection].bytes.size();
                symbolTable.emplace_back(symValue+currSectionSize, symSection, isGlobal, symName, isDefined);
            }
            else if(symSection=="UND")
            {
                symbolTable.emplace_back(0, "UND", isGlobal, symName, false);
            }
            else
            {
                symbolTable.emplace_back(0, "/", isGlobal, symName, true);
                (void)sections[symName];
            }
        }
        else if(symSection=="/" && isGlobal)
        {
            auto entry=std::find(symbolTable.begin(), symbolTable.end(), symName);
            entry->isGlobal=true;
        }
        //simbol je u tabeli simbola i definisan je
        else if(isGlobal && isDefined && symSection!="/")
        {
            auto entry=std::find(symbolTable.begin(), symbolTable.end(), symName);
            if(entry->isDefined)
            {
                std::cout<<"Symbol "<<symName<<" is already defined"<<std::endl;
                return 1;
            }
            entry->isDefined=true;
            entry->symSection=symSection;
            entry->symValue=symValue+sections[symSection].bytes.size();
        }
    }

    size_t sectionsNum;
    in.read(reinterpret_cast<char*>(&sectionsNum), sizeof(size_t));

    for (size_t i = 0; i < sectionsNum; i++)
    {
        std::string sectionName;
        size_t relocEntriesNum;

        size_t readStringSize;
        in.read(reinterpret_cast<char*>(&readStringSize), sizeof(size_t));
        sectionName.resize(readStringSize);
        in.read(&sectionName[0], readStringSize);
        in.read(reinterpret_cast<char*>(&relocEntriesNum), sizeof(size_t));
        for (size_t k = 0; k < relocEntriesNum; k++)
        {
            int offset;
            int addend;
            std::string symbol;

            in.read(reinterpret_cast<char*>(&offset), sizeof(int));
            in.read(reinterpret_cast<char*>(&addend), sizeof(int));
            in.read(reinterpret_cast<char*>(&readStringSize), sizeof(size_t));
            symbol.resize(readStringSize);
            in.read(&symbol[0], readStringSize);

            offset  += sections[sectionName].bytes.size();
            if (sections.find(symbol) != sections.end())
            {
                addend += sections[symbol].bytes.size();
            }

            sections[sectionName].relocationTable.emplace_back(offset, addend, symbol);
        }

        size_t bytesNum;
        in.read(reinterpret_cast<char*>(&bytesNum), sizeof(size_t));
        for (size_t k = 0; k < bytesNum; k++)
        {
            uint8_t byte;
            in.read(reinterpret_cast<char*>(&byte), sizeof(uint8_t));
            sections[sectionName].bytes.push_back(byte);
        }
    }

    in.close();

    return 0;
}
int Linker::parseCallingArguments(int argc, char **argv)
{
    if(argc<2){
        std::cout<<"No input file specified"<<std::endl;
        return 1;
    }

    bool hexOccured=false;
    std::regex placeOptionRegex("-place=([a-zA-Z_][a-zA-Z0-9_]*)@0x([0-9a-fA-F]+)");

    for (int i = 1; i < argc; ++i) {
        if (std::strcmp(argv[i], "-o") == 0) 
        {
            if (i + 1 < argc) {
                this->outputFileName = argv[++i];
            } else {
                std::cout << "error -o without output file name" << std::endl;
                return 1;
            }
        }
        else if(std::regex_match(argv[i], placeOptionRegex))
        {
            std::smatch match_regex;
            std::string arg = argv[i];
            std::regex_search(arg, match_regex, placeOptionRegex);
            std::string sectionName = match_regex[1];
            unsigned long long address=std::stoul(match_regex[2], nullptr, 16);
            if(address>0xffffffffU)
            {
                std::cout<<"Starting address 0x"<<std::hex<<address<< std::dec<< " too big"<<std::endl;
                return 1;
            }
            if(this->parsedSectionsStarts.find(sectionName)!=this->parsedSectionsStarts.end())
            {
                std::cout<<sectionName<<" address configured more than once"<<std::endl;
                return 1;
            }
            this->parsedSectionsStarts[sectionName]=address;
        }
        else if (std::strcmp(argv[i], "-hex") == 0) hexOccured = true;
        else 
        {
            this->inputFileNames.push_back(argv[i]);
        }
    }

    if(!hexOccured)
    {
        std::cout<<"Hex option or relocatable option must be specified"<<std::endl;
        return 1;
    }
    if(this->outputFileName.empty())
    {
        this->outputFileName="emulatorExecutable.hex";
    }

    return 0;
}
void Linker::relocationEntriesResolve()
{
    for(auto& [sectionName, section]: sections){
        for(auto &relocationEntry : section.relocationTable)
        {
            unsigned long value=relocationEntry.addend;
            if(sections.find(relocationEntry.symbol)!=sections.end())
            {
                value += parsedSectionsStarts[relocationEntry.symbol];
            }
            else
            {
                for (auto& symbolEntry : symbolTable)
                {
                    if(symbolEntry.symName==relocationEntry.symbol)
                    {
                        value += symbolEntry.symValue;
                        value += parsedSectionsStarts[symbolEntry.symSection];
                        break;
                    }
                }
            }

            for(int i=0; i<4; i++)
            {
                section.bytes[relocationEntry.offset+i]=(value>>(i*8))&0xFF;
            }
        }
    }
}

int Linker::placeSections()
{
    unsigned long nextStart = 0;
    for(auto& [sectionName, section]: sections)
    {
        if (parsedSectionsStarts.find(sectionName) != parsedSectionsStarts.end())
        {
            nextStart = std::max<unsigned long>(nextStart,parsedSectionsStarts[sectionName]+section.bytes.size());
            for (auto &[secName, secStart] : parsedSectionsStarts)
            {
                if (secName != sectionName && secStart < nextStart + section.bytes.size() && secStart + sections[secName].bytes.size() > nextStart)
                {
                    std::cout << "Sections " << sectionName << " and " << secName << " overlap" << std::endl;
                    return 1;
                }
            }
        }
    }
    for(auto& [sectionName, section]: sections)
    {
        if (parsedSectionsStarts.find(sectionName) == parsedSectionsStarts.end())
        {
            parsedSectionsStarts[sectionName] = nextStart;
            nextStart += section.bytes.size();
        }
    }

    return 0;
}

void Linker::makeExecutableFile()
{
    std::ofstream out(outputFileName);

    
    std::vector<std::pair<std::string, unsigned int>> sectionsByAddresses;
    for (const auto& [sectionName, section] : sections)
    {
        sectionsByAddresses.emplace_back(sectionName, parsedSectionsStarts[sectionName]);
    }

    std::sort(sectionsByAddresses.begin(), sectionsByAddresses.end(), [](const auto& a, const auto& b) {
        return a.second < b.second;
    });
    

    for(const auto& [sectionName, startAddress]: sectionsByAddresses)
    {
        Linker::section& section=sections[sectionName];
        unsigned int i=0;
        while(i<section.bytes.size())
        {
            out<<std::hex<<std::setw(8)<<std::setfill('0')<<startAddress+i<<":\t";
            for(int j=0; j<8; j++)
            {
                if(i+j<section.bytes.size())
                {
                    out<<std::setw(2)<<std::setfill('0')<<(int)section.bytes[i+j]<<" ";
                }
                else{
                    out<<"00 ";
                }
                
                if(j==3)
                {
                    out<<"\t";
                }
                
            }
            out<<std::endl;
            i+=8;
        }
    }
}
int Linker::checkForUndefinedSymbols()const
{
    for(auto& symbolEntry: symbolTable)
    {
        if(!symbolEntry.isDefined || symbolEntry.symSection=="UND")
        {
            std::cout<<symbolEntry.symName<<" is not defined"<<std::endl;
            return 1;
        }
    }

    return 0;
}
std::vector<std::string> Linker::getInputFileNames()
{
    return this->inputFileNames;
}