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
};

#endif