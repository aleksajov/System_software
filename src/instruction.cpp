#include "../inc/instruction.hpp"

void Instruction::halt()
{
    Assembler::getInstance().generateCode(0,0,0,0,0,0);
}