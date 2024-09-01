#ifndef DIRECTIVE_HPP
#define DIRECTIVE_HPP

#include "assembler.hpp"

class Directive{
    public:
        static void skip(unsigned int bytes);
        static void end();
        static void section(std::string name);
        static void global(std::string list_of_syms);
        static void _extern(std::string list_of_syms);
        static void word(std::string list_of_syms_or_literals);


        static std::vector<std::string> splitListOfSyms(const std::string& str, char delimiter);
};



#endif