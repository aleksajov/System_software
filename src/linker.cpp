#include"../inc/linker.hpp"
#include<iostream>
#include<fstream>
#include<cstring>
#include<string>
#include<regex>



int main(int argc, char** argv){
    
    Linker& linker=Linker::getInstance();

    if(linker.parseCallingArguments(argc, argv)!=0) return 1;


    /*
    std::cout<<"Input files: ";
    for(auto& file: linker.inputFileNames)
    {
        std::cout<<file<<" ";
    }
    std::cout<<std::endl;
    std::cout<<"Output file: "<<linker.outputFileName<<std::endl;

    for(auto& section: linker.sections)
    {
        std::cout<<"Section: "<<section.first<<std::endl;
        std::cout<<"Start address: 0x"<<std::hex<<section.second.startAddress<<std::endl;
    }

    */
    
    for(auto& inputFile: linker.inputFileNames)
    {
        if(linker.readFromBinFile(inputFile)!=0) return 1;
    }

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
            if(symSection!="/")
            {
                symbolTable.emplace_back(symValue, symSection, isGlobal, symName, isDefined);
            }
            else
            {
                if(this->parsedSectionsStarts.find(symName)!=this->parsedSectionsStarts.end())
                {
                    symbolTable.emplace_back(this->parsedSectionsStarts[symName], "/", isGlobal, symName, true);
                }
                else{
                    symbolTable.emplace_back(0, "/", isGlobal, symName, true);
                }
            }
        }
        else if(symSection=="/" && isGlobal)
        {
            auto entry=std::find(symbolTable.begin(), symbolTable.end(), symName);
            entry->isGlobal=true;
        }
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
            entry->symValue=symValue;
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