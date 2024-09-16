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

            bool operator==(const std::string& str) const {
                return symName == str;
            }
        };

        void generateCode(uint8_t oc, uint8_t mod, uint8_t rega, uint8_t regb, uint8_t regc, uint16_t disp);

        void handleLabel(std::string label);
        void relocationEntriesResolve();
        
        void printToTxtFile(std::string file);
        void printToBinFile(std::string file);

    private:
        friend class Directive;
        friend class Instruction;

        Assembler() = default;
        Assembler(const Assembler&&) = delete;
        Assembler& operator=(const Assembler&&) = delete;
        
        std::string currSection="";
        std::map<std::string, section> sections;
        std::vector<symbolTableEntry> symbolTable;


        void symbol_or_literal_const_write_to_section(std::string literal_or_symbol);
        void literal_write_to_section(uint32_t literal);
        void checkSectionOpened();
        
};


#endif