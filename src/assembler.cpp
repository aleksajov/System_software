#include "../inc/assembler.hpp"
#include "assembler.hpp"
#include <algorithm>

void Assembler::generateCode(uint8_t oc, uint8_t mod, uint8_t rega, uint8_t regb, uint8_t regc, short int disp)
{
    if(currSection=="")
    {
        std::cerr<<"No section opened"<<std::endl;
        return;
    }
    
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
    if(currSection=="")
    {
        std::cout<<"No section opened"<<std::endl;
        exit(1);
    }
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