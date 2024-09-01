#ifndef ASSEMBLER_HPP
#define ASSEMBLER_HPP

#include <map>
#include <vector>
#include <string>
#include <cstddef>
#include <iostream>

class Assembler {
    public:


        static Assembler& getInstance() {
            static Assembler instance;
            return instance;
        }

        Assembler(const Assembler&) = delete;
        Assembler& operator=(const Assembler&) = delete;

        
        
        struct relocationTableEntry{
            int offset;
            int addend;
            std::string symbol;
            relocationTableEntry(int offset, int addend, std::string symbol): offset(offset), addend(addend), symbol(symbol){}
        };
        struct section{
            std::vector<uint8_t> bytes;
            std::vector<relocationTableEntry> relocationTable;
        };
        struct symbolTableEntry{
            unsigned int symValue;
            std::string symSection;
            bool isGlobal;
            std::string symName;
            bool isDefined;

            /*
            enum class SymbolType{
            SECTION,
            LABEL
            } symType;
            */

            bool operator==(const std::string& other) const {
                return symName == other;
            }
        };

        void generateCode(uint8_t oc, uint8_t mod, uint8_t rega, uint8_t regb, uint8_t regc, short int disp);

        void handleLabel(std::string label);

        


    private:
        friend class Directive;
        friend class Instruction;

        Assembler() = default;
        std::string currSection="";
        std::map<std::string, section> sections;
        std::vector<symbolTableEntry> symbolTable;
        
};


#endif