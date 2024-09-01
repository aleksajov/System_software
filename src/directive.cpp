#include "../inc/directive.hpp"
#include <algorithm>
#include <vector>
#include <sstream>

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
        assembler.symbolTable.push_back(Assembler::symbolTableEntry{0, "/", false, name, true});
    }
    else{
        for(auto& entry : assembler.symbolTable){
            if(entry.symName==name){
                entry.symSection="/";
                entry.isDefined=true;
                break;
            }
        }
    }
}
void Directive::global(std::string list_of_syms)
{
    Assembler& assembler=Assembler::getInstance();
    std::vector<std::string> symbols = splitListOfSyms(list_of_syms, ' ');

    for (const auto& sym : symbols) {
        bool found = false;
        for (auto& entry : assembler.symbolTable) {
            if (entry.symName == sym) {
                entry.isGlobal = true;
                found = true;
                break;
            }
        }
        if (!found) {
            assembler.symbolTable.push_back(Assembler::symbolTableEntry{0, "UND", true, sym, false});
        }
    }
/*
    unsigned int symValue;
            std::string symSection;
            bool isGlobal;
            std::string symName;
            bool isDefined;
            */
}
void Directive::_extern(std::string list_of_syms)
{
    Assembler& assembler=Assembler::getInstance();
    std::vector<std::string> symbols = splitListOfSyms(list_of_syms, ' ');

    for (const auto& sym : symbols) {
        bool found = false;
        for (auto& entry : assembler.symbolTable) {
            if(entry.symName == sym && entry.isDefined){
                std::cout<<"Symbol "<<sym<<" tried to be declared as extern, but already defined"<<std::endl;
                exit(1);
            }
            if (entry.symName == sym) {
                entry.isGlobal = true;
                found = true;
                break;
            }
        }
        if (!found) {
            assembler.symbolTable.push_back(Assembler::symbolTableEntry{0, "UND", true, sym, false});
        }
    }
}

void Directive::word(std::string list_of_syms_or_literals)
{
    Assembler& assembler=Assembler::getInstance();
    std::vector<std::string> symbols = splitListOfSyms(list_of_syms_or_literals, ' ');

    for(const auto& sym : symbols){
        assembler.symbol_or_literal_const_write_to_section(sym);
    }
}
std::vector<std::string> Directive::splitListOfSyms(const std::string& str, char delimiter) {
    std::vector<std::string> syms;
    std::string sym;
    std::stringstream ss(str);
    
    while (std::getline(ss, sym, delimiter)) {
        syms.push_back(sym);
    }
    return syms;
}