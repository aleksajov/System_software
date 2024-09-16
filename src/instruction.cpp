#include "../inc/instruction.hpp"
#include "../inc/directive.hpp"
#include "instruction.hpp"

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
    Assembler::getInstance().generateCode(0x2, 0x1, 15, 0, 0, 4);
    Assembler::getInstance().generateCode(0x3, 0x0, 15, 0x0, 0x0, 0x4);
    Assembler::getInstance().symbol_or_literal_const_write_to_section(literal_or_symbol);
}

void Instruction::load_imm_literal(uint32_t literal, uint8_t reg)
{
    Assembler& ass=Assembler::getInstance();
    ass.generateCode(0x9, 0x2, reg, 15, 0, 4);
    ass.generateCode(0x3, 0x0, 15, 0x0, 0x0, 0x4);
    ass.literal_write_to_section(literal);
}
void Instruction::load_imm_symbol(std::string symbol, uint8_t reg)
{
    Assembler& ass=Assembler::getInstance();
    ass.generateCode(0x9, 0x2, reg, 15, 0, 4);
    ass.generateCode(0x3, 0x0, 15, 0x0, 0x0, 0x4);
    int lc=ass.sections[ass.currSection].bytes.size();
    ass.sections[ass.currSection].relocationTable.emplace_back(lc, 0, symbol);
    Directive::skip(4);
}

void Instruction::load_literal(uint32_t literal, uint8_t reg)
{
    Assembler& ass=Assembler::getInstance();
    ass.generateCode(0x9, 0x2, reg, 15, 0, 4);
    ass.generateCode(0x3, 0x0, 15, 0x0, 0x0, 0x4);
    ass.literal_write_to_section(literal);
    ass.generateCode(9, 2, reg, reg, 0, 0);
}

void Instruction::load_symbol(std::string symbol, uint8_t reg)
{
    Assembler& ass=Assembler::getInstance();
    ass.generateCode(0x9, 0x2, reg, 15, 0, 4);
    ass.generateCode(0x3, 0x0, 15, 0x0, 0x0, 0x4);
    int lc=ass.sections[ass.currSection].bytes.size();
    ass.sections[ass.currSection].relocationTable.emplace_back(lc, 0, symbol);
    Directive::skip(4);
    ass.generateCode(9, 2, reg, reg, 0, 0);
}

void Instruction::load_regdir(uint8_t gprs, uint8_t gprd)
{
    Assembler::getInstance().generateCode(0x9, 0x1, gprd, gprs, 0, 0);
}

void Instruction::load_reg_ind(uint8_t gprs, uint8_t gprd)
{
    Assembler::getInstance().generateCode(0x9, 0x2, gprd, gprs, 0, 0);
}
void Instruction::load_reg_ind_offset(uint16_t offset, uint8_t gprs, uint8_t gprd)
{
    if(offset>0xfff){
        std::cout<<"Offset "<<std::hex<<offset<<std::dec<<" larger than 12 bits"<<std::endl;
        exit(1);
    }
    Assembler::getInstance().generateCode(0x9, 0x2, gprd, gprs, 0, offset&0xfff);
}
void Instruction::store_literal(uint8_t reg, uint32_t literal)
{
    Assembler& ass=Assembler::getInstance();
    ass.generateCode(0x8, 0x2, 15, 0, reg, 4);
    ass.generateCode(0x3, 0x0, 15, 0, 0, 4);
    ass.literal_write_to_section(literal);
}
void Instruction::store_symbol(uint8_t reg, std::string symbol)
{
    Assembler& ass=Assembler::getInstance();
    ass.generateCode(0x8, 0x2, 15, 0, reg, 4);
    ass.generateCode(0x3, 0x0, 15, 0, 0, 4);
    int lc=ass.sections[ass.currSection].bytes.size();
    ass.sections[ass.currSection].relocationTable.emplace_back(lc, 0, symbol);
    Directive::skip(4);
}
void Instruction::store_regind(uint8_t gprs, uint8_t gpraddress)
{
    Assembler::getInstance().generateCode(0x8, 0x0, gpraddress, 0, gprs, 0);
}
void Instruction::store_regind_offs(uint16_t offset, uint8_t gprs, uint8_t gpraddress)
{
    if(offset>0xfff){
        std::cout<<"Offset "<<std::hex<<offset<<std::dec<<" larger than 12 bits"<<std::endl;
        exit(1);
    }
    Assembler::getInstance().generateCode(0x8, 0, gpraddress, 0, gprs, offset);
}
void Instruction::ld_regPlusReg(uint8_t reg1, uint8_t reg2, uint8_t regd)
{
    Assembler::getInstance().generateCode(0x9, 0x2, regd, reg1, reg2, 0);
}
void Instruction::st_regPlusReg(uint8_t regs, uint8_t reg1, uint8_t reg2)
{
    Assembler::getInstance().generateCode(0x8, 0, reg1, reg2, regs, 0);
}
void Instruction::branches(uint8_t gpr1, uint8_t gpr2, std::string literal_or_symbol, uint8_t mmmm)
{
    Assembler& assembler=Assembler::getInstance();
    assembler.generateCode(0x3, mmmm, 15, gpr1, gpr2, 0x4);
    assembler.generateCode(0x3, 0x0, 15, 0x0, 0x0, 0x4);
    
    assembler.symbol_or_literal_const_write_to_section(literal_or_symbol);
}
