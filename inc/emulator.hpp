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

        int readExecutableFile(std::string file);


    private:
        Emulator()=default;
        Emulator(const Emulator&) = delete;
        Emulator& operator=(const Emulator&) = delete;

        uint32_t startExecution=0x40000000;
        std::map<uint32_t, uint8_t> memory;
        std::vector<uint32_t> registers;

        uint32_t status;
        uint32_t handler;
        uint32_t cause;
};



#endif