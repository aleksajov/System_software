#ifndef INSTRUCTION_HPP
#define INSTRUCTION_HPP

#include "assembler.hpp"

class Instruction{
    public:
        static void halt();
        static void add(uint8_t rega, uint8_t regb);
        static void sub(uint8_t rega, uint8_t regb);
        static void mul(uint8_t rega, uint8_t regb);
        static void div(uint8_t rega, uint8_t regb);
        static void _not(uint8_t rega);
        static void _and(uint8_t rega, uint8_t regb);
        static void _or(uint8_t rega, uint8_t regb);
        static void _xor(uint8_t rega, uint8_t regb);
        static void shl(uint8_t rega, uint8_t regb);
        static void shr(uint8_t rega, uint8_t regb);
        static void csrrd(uint8_t csr, uint8_t gpr);
        static void csrrw(uint8_t gpr, uint8_t csr);
        static void xchg(uint8_t rega, uint8_t regb);
        static void pop(uint8_t gpr);
        static void push(uint8_t gpr);
        static void interrupt();
        static void ret();
        static void iret();
        static void jmp(std::string literal_or_symbol);
        static void beq(uint8_t gpr1, uint8_t gpr2, std::string literal_or_symbol);
        static void bne(uint8_t gpr1, uint8_t gpr2, std::string literal_or_symbol);
        static void bgt(uint8_t gpr1, uint8_t gpr2, std::string literal_or_symbol);
        static void call(std::string literal_or_symbol);


        static void load_imm_literal(uint32_t literal, uint8_t reg);
        static void load_imm_symbol(std::string symbol, uint8_t reg);
        static void load_literal(uint32_t literal, uint8_t reg);
        static void load_symbol(std::string symbol, uint8_t reg);
        static void load_regdir(uint8_t gprs, uint8_t gprd);
        static void load_reg_ind(uint8_t gprs, uint8_t gprd);
        static void load_reg_ind_offset(uint16_t offset, uint8_t gprs, uint8_t gprd);
        
    private:
        static void branches(uint8_t gpr1, uint8_t gpr2, std::string literal_or_symbol, uint8_t mmmm);
};

#endif