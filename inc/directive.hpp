#ifndef DIRECTIVE_HPP
#define DIRECTIVE_HPP

#include "assembler.hpp"

class Directive{
    public:
        static void skip(unsigned int bytes);
        static void end();
        static void section(std::string name);
        static void global(std::string list_of_syms);
};



#endif