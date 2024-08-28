#ifndef INSTRUCTION_HPP
#define INSTRUCTION_HPP

#include "assembler.hpp"

class Instruction{
    public:
        static void halt();
        static void add();
        static void sub();
        static void mul();
        static void div();
    
};

#endif