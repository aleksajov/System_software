#include "../inc/instruction.hpp"

void Instruction::halt()
{
    
    Assembler::getInstance().generateCode(0,0,0,0,0,0);
}
void Instruction::sub(uint8_t rega, uint8_t regb)
{
    
    Assembler::getInstance().generateCode(0x5,0x1, rega, rega, regb, 0);
    
}
void Instruction::mul(uint8_t rega, uint8_t regb)
{
    Assembler::getInstance().generateCode(0x5,0x2, rega, rega, regb, 0);
    
}
void Instruction::div(uint8_t rega, uint8_t regb)
{
    
    Assembler::getInstance().generateCode(0x5,0x3, rega, rega, regb, 0);
    
}
void Instruction::add(uint8_t rega, uint8_t regb)
{
    
    Assembler::getInstance().generateCode(0x5,0x0, rega, rega, regb, 0);
    
}

void Instruction::_not(uint8_t rega)
{
    
    Assembler::getInstance().generateCode(0x6,0x0, rega, rega, 0, 0);
    
}
void Instruction::_and(uint8_t rega, uint8_t regb)
{
    
    Assembler::getInstance().generateCode(0x6,0x1, rega, rega, regb, 0);
    
}
void Instruction::_or(uint8_t rega, uint8_t regb)
{
    
    Assembler::getInstance().generateCode(0x6,0x2, rega, rega, regb, 0);
    
}
void Instruction::_xor(uint8_t rega, uint8_t regb)
{
    
    Assembler::getInstance().generateCode(0x6,0x3, rega, rega, regb, 0);
    
}

void Instruction::shl(uint8_t rega, uint8_t regb)
{
    
    Assembler::getInstance().generateCode(0x7,0x0, rega, rega, regb, 0);
    
}
void Instruction::shr(uint8_t rega, uint8_t regb)
{
    Assembler::getInstance().generateCode(0x7,0x1, rega, rega, regb, 0);
}