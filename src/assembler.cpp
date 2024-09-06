#include "../inc/assembler.hpp"
#include "../inc/directive.hpp"
#include <algorithm>
#include <stdio.h>
#include <stdlib.h>
#include <fstream>
#include <iomanip>
#include <filesystem>
#include <cstring>

extern int yyparse();
extern FILE *yyin;

int main(int argc, char** argv) {
    if(argc<2){
        std::cout<<"No input file specified"<<std::endl;
        return 1;
    }

    std::string inputName;
    std::string outputName;

    for (int i = 1; i < argc; ++i) {
        if (std::strcmp(argv[i], "-o") == 0) {
            if (i + 1 < argc) {
                outputName = argv[++i];
            } else {
                std::cout << "error -o without output file name" << std::endl;
                return 1;
            }
        } else {
            inputName = argv[i];
        }
    }

    if(inputName.empty()){
        std::cout<<"No input file specified"<<std::endl;
        return 1;
    }
    if(outputName.empty()){
        std::filesystem::path filePath(inputName);
        outputName = filePath.stem().string()+".o";
    }



    FILE *myfile = fopen(inputName.c_str(), "r");
    if (!myfile) {
        std::cout<<"Error opening input file\n"<<std::endl;
        return 1;
    }
    yyin = myfile;
    yyparse();
    fclose(myfile);

    Assembler &ass=Assembler::getInstance();

    ass.relocationEntriesResolve();
    ass.printToTxtFile(outputName+".txt");
    ass.printToBinFile(outputName);

    return 0;
}

void Assembler::generateCode(uint8_t oc, uint8_t mod, uint8_t rega, uint8_t regb, uint8_t regc, short int disp)
{
    checkSectionOpened();
    
    uint8_t byte = (oc<<4)|(mod&0x0F);
    sections[currSection].bytes.push_back(byte);
    byte = (rega<<4)|(regb&0x0F);
    sections[currSection].bytes.push_back(byte);
    byte = (regc<<4)|(((uint8_t)(disp>>8))&0x0F);
    sections[currSection].bytes.push_back(byte);
    byte = (uint8_t)(disp&0xFF);
    sections[currSection].bytes.push_back(byte);
}

void Assembler::handleLabel(std::string label)
{
    checkSectionOpened();

    uint32_t lc=sections[currSection].bytes.size();
    if(std::find(symbolTable.begin(), symbolTable.end(), label) == symbolTable.end())
    {
        symbolTable.push_back(symbolTableEntry{lc, currSection, false, label, true});
        return;
    }
    
    for(auto& entry : symbolTable)
    {
        if(entry.symName==label)
        {
            if(entry.isDefined)
            {
                std::cout<<"Symbol "<<label<<" is already defined"<<std::endl;
                exit(1);
            }
            entry.symValue=lc;
            entry.symSection=currSection;
            entry.isDefined=true;
            break;
        }
    }
    
}

void Assembler::relocationEntriesResolve()
{
    for(auto& [sectionName, section]: sections){
        for(auto &relTableEntry : section.relocationTable)
        {
            bool found=false;
            for(auto &symTableEntry: symbolTable)
            {
                if(symTableEntry.symName==relTableEntry.symbol)
                {
                    found=true;
                    if(!symTableEntry.isGlobal)
                    {
                        relTableEntry.addend=symTableEntry.symValue;
                        relTableEntry.symbol=symTableEntry.symSection;
                    }
                    break;
                }
            }
            if(!found)
            {
                std::cout<<"Symbol "<<relTableEntry.symbol<<" is not defined"<<std::endl;
                exit(1);
            }
        }
    }
}

void Assembler::printToTxtFile(std::string file)
{
    std::ofstream out(file, std::ios::out | std::ios::binary);
    if(!out)
    {
        std::cout<<"Error opening file "<<file<<std::endl;
        exit(1);
    }

    out << "Symbol table:" << std::endl;
    out << std::left << std::setw(15) << "symbolName";
    out << std::left << std::setw(15) << "symValue";
    out << std::left << std::setw(15) << "symSection";
    out << std::left << std::setw(10) << "global";
    out << std::left << std::setw(10) << "defined" << std::endl;
    for (auto& entry : symbolTable)
    {
        if (entry.isGlobal || entry.symSection == "/") {
            out << std::left << std::setw(15) << entry.symName;
            out << std::left << std::setw(15) << entry.symValue;
            out << std::left << std::setw(15) << entry.symSection;
            out << std::left << std::setw(10) << (entry.isGlobal ? "global" : "local");
            out << std::left << std::setw(10) << (entry.isDefined ? "def" : "und") << std::endl;
        }
    }
    out<<std::endl<<std::endl;

    for(auto& [sectionName, section]: sections)
    {
        out<<"Section "<<sectionName<<std::endl<<"Relocation table:"<<std::endl;
        out<<"offset\t"<<"addend\t"<<"symbol"<<std::endl;
        for(auto &relEntry: section.relocationTable)
        {
            out<<std::hex<<"0x"<<relEntry.offset<<"\t0x"<<relEntry.addend<<"\t"<<relEntry.symbol<<std::endl;
        }

        out<<"Section content:"<<std::endl;
        for(size_t i=0; i<section.bytes.size(); i++)
        {
            out<<std::hex<<std::setw(2)<<std::setfill('0')<<(int)section.bytes[i];
            if((i+1)%8==0)
                out<<std::endl;
            else if((i+1)%4==0)
                out<<"\t\t";
            else
                out<<" ";
        }
        out<<std::endl<<std::endl;
    }

    out.close();
}

void Assembler::printToBinFile(std::string file)
{
    std::ofstream out(file, std::ios::binary);
    if(!out)
    {
        std::cout<<"Error opening file "<<file<<std::endl;
        exit(1);
    }

    std::vector<symbolTableEntry> newSymbolTable;
    for(auto& entry : symbolTable)
    {
        if(entry.isGlobal || entry.symSection == "/")
        {
            newSymbolTable.push_back(entry);
        }
    }

    size_t newSymbolTableSize = newSymbolTable.size();
    out.write(reinterpret_cast<const char*>(&newSymbolTableSize), sizeof(size_t));


    for (auto& entry : newSymbolTable)
    {
        size_t writtenStringSize = entry.symName.size();
        out.write(reinterpret_cast<const char*>(&writtenStringSize), sizeof(size_t));
        out.write(entry.symName.c_str(), writtenStringSize);
        out.write(reinterpret_cast<const char*>(&entry.symValue), sizeof(unsigned int));
        writtenStringSize = entry.symSection.size();
        out.write(reinterpret_cast<const char*>(&writtenStringSize), sizeof(size_t));
        out.write(entry.symSection.c_str(), writtenStringSize);
        out.write(reinterpret_cast<const char*>(&entry.isGlobal), sizeof(bool));
        out.write(reinterpret_cast<const char*>(&entry.isDefined), sizeof(bool));
    }

    size_t sectionsNum = sections.size();
    out.write(reinterpret_cast<const char*>(&sectionsNum), sizeof(size_t));

    for(auto& [sectionName, section]: sections)
    {
        size_t writtenStringSize = sectionName.size();
        out.write(reinterpret_cast<const char*>(&writtenStringSize), sizeof(size_t));
        out.write(sectionName.c_str(), writtenStringSize);
        size_t relocEntriesNum=section.relocationTable.size();
        out.write(reinterpret_cast<const char*>(&relocEntriesNum), sizeof(size_t));
        for(auto& relocEntry: section.relocationTable)
        {
            out.write(reinterpret_cast<const char*>(&relocEntry.offset), sizeof(int));
            out.write(reinterpret_cast<const char*>(&relocEntry.addend), sizeof(int));
            writtenStringSize=relocEntry.symbol.size();
            out.write(reinterpret_cast<const char*>(&writtenStringSize), sizeof(size_t));
            out.write(relocEntry.symbol.c_str(), writtenStringSize);
        }
        size_t bytesNum=section.bytes.size();
        out.write(reinterpret_cast<const char*>(&bytesNum), sizeof(size_t));
        for(auto& byte: section.bytes)
        {
            out.write(reinterpret_cast<const char*>(&byte), sizeof(uint8_t));
        }
    }
    out.close();
    
}
void Assembler::symbol_or_literal_const_write_to_section(std::string literal_or_symbol)
{
    checkSectionOpened();
    Assembler& assembler=Assembler::getInstance();
    try{
        unsigned long long literal = std::stoull(literal_or_symbol);
        if (literal > 0xFFFFFFFFUL) {
            std::cout << std::hex << literal << " is larger than 4 bytes" << std::dec <<std::endl;
            exit(1);
        }
        for(int i=0; i<4; i++){
            assembler.sections[assembler.currSection].bytes.push_back((literal>>(i*8))&0xFF);
        }
    }
    catch(...) {
        assembler.sections[assembler.currSection].relocationTable.emplace_back(assembler.sections[assembler.currSection].bytes.size(), 0, literal_or_symbol);
        Directive::skip(4);
    }
}

void Assembler::literal_write_to_section(uint32_t literal)
{
    checkSectionOpened();
    Assembler& assembler=Assembler::getInstance();
    if (literal > 0xFFFFFFFFU) {
        std::cout << std::hex << literal << " is larger than 4 bytes" << std::dec <<std::endl;
        exit(1);
    }
    for(int i=0; i<4; i++){
        assembler.sections[assembler.currSection].bytes.push_back((literal>>(i*8))&0xFF);
    }
}

void Assembler::checkSectionOpened()
{
    if(currSection=="")
    {
        std::cout<<"No section opened"<<std::endl;
        exit(1);
    }
}
