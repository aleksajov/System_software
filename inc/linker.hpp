#ifndef LINKER_HPP
#define LINKER_HPP
#include<string>
#include<vector>
#include<map>

class Linker{
    public:
        static Linker& getInstance(){
            static Linker instance;
            return instance;
        }

        struct symbolTableEntry{
            unsigned int symValue;
            std::string symSection;
            bool isGlobal;
            std::string symName;
            bool isDefined;

            bool operator==(const std::string& str) const {
                return symName == str;
            }

            symbolTableEntry(unsigned int symValue, std::string symSection, bool isGlobal, std::string symName, bool isDefined): symValue(symValue), symSection(symSection), isGlobal(isGlobal), symName(symName), isDefined(isDefined){}
        };
        struct relocationTableEntry{
            int offset;
            int addend;
            std::string symbol;
            relocationTableEntry(int offset, int addend, std::string symbol): offset(offset), addend(addend), symbol(symbol){}

        };
        struct section{
            std::vector<uint8_t> bytes;
            std::vector<relocationTableEntry> relocationTable;
            unsigned int startAddress;
            unsigned int size;
        };

        int readFromBinFile(std::string file);


        int parseCallingArguments(int argc, char** argv);



    private:
        Linker() = default;
        Linker(const Linker&) = delete;
        Linker& operator=(const Linker&) = delete;

        std::vector<symbolTableEntry> symbolTable;
        std::map<std::string, section> sections;
        std::vector<std::string> inputFileNames;
        std::string outputFileName;
        std::map<std::string, unsigned int> parsedSectionsStarts;

        friend int main(int argc, char** argv);
};

#endif