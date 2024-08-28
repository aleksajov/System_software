#include "../inc/directive.hpp"

void Directive::skip(unsigned int bytes)
{
    for(unsigned int i=0; i<bytes; i++)
    {
        Assembler::getInstance().sections[Assembler::getInstance().currSection].bytes.push_back(0);
    }
}