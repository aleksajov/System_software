#ifndef ASSEMBLER_HPP
#define ASSEMBLER_HPP

#include <map>
#include <vector>
#include <string>
#include <cstddef>

class Assembler {
    public:

        static Assembler& getInstance() {
            static Assembler instance;
            return instance;
        }

        Assembler(const Assembler&) = delete;
        Assembler& operator=(const Assembler&) = delete;
        
        struct relocationTable{
            int offset;
            int addend;
            std::string symbol;
        };
        struct section{
            std::vector<uint8_t> bytes;
            std::vector<relocationTable> relocationTables;
        };
        struct symbolTableEntry{
            unsigned int symValue;
            std::string symSection;
            bool isGlobal;
            std::string symName;
            bool isDefined;
        };

        void generateCode(uint8_t oc, uint8_t mod, uint8_t rega, uint8_t regb, uint8_t regc, short int disp);


    private:
        friend class Directive;
        friend class Instruction;

        Assembler() = default;
        std::string currSection="sekcija";
        std::map<std::string, section> sections;
        std::vector<symbolTableEntry> symbolTable;
};


#endif