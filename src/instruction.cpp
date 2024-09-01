#include "../inc/instruction.hpp"
#include "../inc/directive.hpp"

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
    Assembler::getInstance().generateCode(0x9, 0x3, gpr, 14, 0, 0x4);
}

void Instruction::push(uint8_t gpr)
{
    Assembler::getInstance().generateCode(0x8, 0x1, 14, 0x0, gpr, -4);
}

void Instruction::interrupt()
{
    Assembler::getInstance().generateCode(0x1, 0x0, 0x0, 0x0, 0x0, 0x0);
}

void Instruction::ret()
{
    Instruction::pop(15);
}
void Instruction::iret()
{
    Assembler::getInstance().generateCode(0x9, 0x6, 0x0, 14, 0x0, 0x4);
    Assembler::getInstance().generateCode(0x9, 0x3, 15, 14, 0x0, 0x8);
}
void Instruction::jmp(std::string literal_or_symbol)
{
    Assembler& assembler=Assembler::getInstance();
    assembler.generateCode(0x3, 0x8, 15, 0x0, 0x0, 0x0);
    assembler.symbol_or_literal_const_write_to_section(literal_or_symbol);
}
void Instruction::beq(uint8_t gpr1, uint8_t gpr2, std::string literal_or_symbol)
{
    branches(gpr1, gpr2, literal_or_symbol, 0x9);
}

void Instruction::bne(uint8_t gpr1, uint8_t gpr2, std::string literal_or_symbol)
{
    branches(gpr1, gpr2, literal_or_symbol, 0xa);
}
void Instruction::bgt(uint8_t gpr1, uint8_t gpr2, std::string literal_or_symbol)
{
    branches(gpr1, gpr2, literal_or_symbol, 0xb);
}

void Instruction::call(std::string literal_or_symbol)
{
    Assembler::getInstance().generateCode(0x2, 0x1, 15, 0, 0, 0);
    Assembler::getInstance().symbol_or_literal_const_write_to_section(literal_or_symbol);
}

void Instruction::branches(uint8_t gpr1, uint8_t gpr2, std::string literal_or_symbol, uint8_t mmmm)
{
    Assembler& assembler=Assembler::getInstance();
    assembler.generateCode(0x3, mmmm, 15, gpr1, gpr2, 0x4);
    assembler.generateCode(0x3, 0x0, 15, 0x0, 0x0, 0x4);
    
    assembler.symbol_or_literal_const_write_to_section(literal_or_symbol);
}
