#include "../inc/directive.hpp"
#include <algorithm>

void Directive::skip(unsigned int bytes)
{
    
    for(unsigned int i=0; i<bytes; i++)
    {
        Assembler::getInstance().sections[Assembler::getInstance().currSection].bytes.push_back(0);
    }
    
}
void Directive::end()
{
    Assembler::getInstance().currSection="";
}
void Directive::section(std::string name)
{
    
    Assembler& assembler=Assembler::getInstance();
    if (assembler.sections.find(name) == assembler.sections.end()) {
        assembler.sections[name] = Assembler::section();
    }
    assembler.currSection=name;
    if(std::find(assembler.symbolTable.begin(), assembler.symbolTable.end(), name) == assembler.symbolTable.end()){
        assembler.symbolTable.push_back(Assembler::symbolTableEntry{0, "", false, name, true, Assembler::symbolTableEntry::SymbolType::SECTION});
    }
}
void Directive::global(std::string list_of_syms)
{
    Assembler& assembler=Assembler::getInstance();
    std::string delimiter = " ";
    size_t pos = 0;
    while((pos = list_of_syms.find(delimiter)) != std::string::npos){
        std::string sym = list_of_syms.substr(0, pos);
        
        list_of_syms.erase(0, pos + delimiter.length());
    }
    
}