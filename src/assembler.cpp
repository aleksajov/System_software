#include "../inc/assembler.hpp"

void Assembler::generateCode(uint8_t oc, uint8_t mod, uint8_t rega, uint8_t regb, uint8_t regc, short int disp)
{
    uint8_t byte = (oc<<4)|(mod&0x0F);
    sections[currSection].bytes.push_back(byte);
    byte = (rega<<4)|(regb&0x0F);
    sections[currSection].bytes.push_back(byte);
    byte = (regc<<4)|(((uint8_t)(disp>>8))&0x0F);
    sections[currSection].bytes.push_back(byte);
    byte = (uint8_t)(disp&0xFF);
    sections[currSection].bytes.push_back(byte);
}