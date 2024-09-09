#ifndef EMULATOR_HPP
#define EMULATOR_HPP

#include<map>
#include<iostream>
#include<vector>

class Emulator {
    public:
        static Emulator& getInstance() {
            static Emulator instance;
            return instance;
        }

        void readExecutableFile(std::string file);
        void executeProgram();

        uint32_t getRegisterValue(uint32_t reg) const {
            return registers[reg];
        }

        void halt();
        void interrupt();
        void call(uint32_t instr);
        void branches(uint32_t instr);
        void xchg(uint8_t gprb, uint8_t gprc);
        void aritmeticalOperations(uint32_t instr);
        void logicalOperations(uint32_t instr);
        void shiftOperations(uint32_t instr);
        void storeOperations(uint32_t instr);
        void loadOperations(uint32_t instr);

        void push(uint32_t val);
        uint32_t pop();
        uint32_t get32Memory(uint32_t address);
        void set32Memory(uint32_t address, uint32_t val);
        void setRegisterVal(uint8_t r, uint32_t val);

        uint32_t getInstruction();

        void printProcessorState();

        enum Csr{STATUS, HANDLER, CAUSE};

    private:
        Emulator():registers(16, 0), csr(3, 0){}
        Emulator(const Emulator&) = delete;
        Emulator& operator=(const Emulator&) = delete;

        const uint32_t startingAddress=0x40000000;
        bool finish=false;
        std::map<uint32_t, uint8_t> memory;
        std::vector<uint32_t> registers;
        std::uint32_t& pc=registers[15];
        std::uint32_t& sp=registers[14];

        std::vector<uint32_t> csr;
};



#endif