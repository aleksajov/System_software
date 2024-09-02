#include "../inc/assembler.hpp"
#include "assembler.hpp"
#include "directive.hpp"
#include <algorithm>

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
    /*
    unsigned int symValue;
            std::string symSection;
            bool isGlobal;
            std::string symName;
            bool isDefined;
            */
    
    
}

void Assembler::symbol_or_literal_const_write_to_section(std::string literal_or_symbol)
{
    checkSectionOpened();
    Assembler& assembler=Assembler::getInstance();
    try{
        unsigned long long literal=std::stoull(literal_or_symbol);
        if (literal > 0xFFFFFFFF) {
            std::cout << literal_or_symbol << " is larger than 4 bytes" << std::endl;
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
    if (literal > 0xFFFFFFFF) {
        std::cout << literal << " is larger than 4 bytes" << std::endl;
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
