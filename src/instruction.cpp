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
void Instruction::csrrd(uint8_t csr, uint8_t gpr)
{
    Assembler::getInstance().generateCode(0x9, 0x0, gpr, csr, 0, 0);
}

void Instruction::csrrw(uint8_t gpr, uint8_t csr)
{
    Assembler::getInstance().generateCode(0x9, 0x4, csr, gpr, 0, 0);
}

void Instruction::xchg(uint8_t gprs, uint8_t gprd)
{
    Assembler::getInstance().generateCode(0x4, 0x0, 0x0, gprd, gprs, 0);
}

void Instruction::pop(uint8_t gpr)
{
    Assembler::getInstance().generateCode(0x9, 0x3, gpr, 0x14, 0, 0x4);
}

void Instruction::push(uint8_t gpr)
{
    Assembler::getInstance().generateCode(0x8, 0x1, 0x14, 0x0, gpr, -4);
}

void Instruction::interrupt()
{
    Assembler::getInstance().generateCode(0x1, 0x0, 0x0, 0x0, 0x0, 0x0);
}

void Instruction::ret()
{
    Instruction::pop(0x15);
}