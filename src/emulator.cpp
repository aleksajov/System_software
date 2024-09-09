#include"../inc/emulator.hpp"
#include<fstream>
#include<regex>
#include<iomanip>

int main(int argc, char** argv){

    if(argc<2){
        std::cout<<"No input file specified"<<std::endl;
        return 1;
    }
    Emulator& emulator=Emulator::getInstance();
    
    try
    {
        emulator.readExecutableFile(argv[1]);
        emulator.executeProgram();
        emulator.printProcessorState();
        return 0;
    }
    catch(const std::exception& e)
    {
        std::cout << e.what() << std::endl;
        return 1;
    }
}
void Emulator::readExecutableFile(std::string file)
{
    std::ifstream in(file);
    if(!in)
    {
        throw std::invalid_argument("Error opening file "+file);
    }

    std::regex lineRegex("([a-fA-F0-9]{8}):\\s+([a-fA-F0-9]{2})\\s*([a-fA-F0-9]{2})\\s*([a-fA-F0-9]{2})\\s*([a-fA-F0-9]{2})\\s*([a-fA-F0-9]{2})\\s*([a-fA-F0-9]{2})\\s*([a-fA-F0-9]{2})\\s*([a-fA-F0-9]{2})");
    std::string line;
    while(std::getline(in, line)){
        std::smatch match;
        if(std::regex_search(line, match, lineRegex)){
            uint32_t address=std::stoul(match.str(1), nullptr, 16);
            for (size_t i = 2; i < 10; i++) {
                uint8_t byte = std::stoul(match.str(i), nullptr, 16);
                this->memory[address++]=byte;
            }
            
        }
        else{
            throw std::runtime_error("Executable file not in correct format");
        }
    }
    in.close();
}
void Emulator::executeProgram()
{
    this->pc=this->startingAddress;
    this->sp=0xffffff00;

    while(!this->finish){
        uint32_t instr=this->getInstruction();
        uint8_t oc=instr>>28;
        switch(oc)
        {
            case 0x0:
                this->halt();
                break;

            case 0x1:
                this->interrupt();
                break;

            case 0x2:
                this->call(instr);
                break;

            case 0x3:
                this->branches(instr);
                break;

            case 0x4:
                this->xchg((instr>>16)&0xf, (instr>>12)&0xf);
                break;

            case 0x5:
                this->aritmeticalOperations(instr);
                break;

            case 0x6:
                this->logicalOperations(instr);
                break;

            case 0x7:
                this->shiftOperations(instr);
                break;

            case 0x8:
                this->storeOperations(instr);
                break;

            case 0x9:
                this->loadOperations(instr);
                break;
                
            default:
                throw std::runtime_error("Unknown opcode");
        }
    }
}
void Emulator::halt()
{
    this->finish=true;
}

void Emulator::interrupt()
{
    this->push(this->csr[STATUS]);
    this->push(this->pc);
    this->csr[CAUSE]=4;
    this->csr[STATUS]=(this->csr[STATUS])&(~0x1); 
    this->pc=this->csr[HANDLER];
}

void Emulator::call(uint32_t instr)
{
    uint8_t mod, gpra, gprb;  uint16_t dddd;
    mod=(instr>>24)&0xf;
    gpra=(instr>>20)&0xf;
    gprb=(instr>>16)&0xf;
    dddd=instr&0xfff;
    int32_t signedDisplacement=((int32_t)(dddd<<20))>>20;

    this->push(this->pc);
    
    if(mod==0)
    {
        this->pc=(int32_t)registers[gpra]+(int32_t)registers[gprb]+signedDisplacement;
    }
    else if(mod==1)
    {
        
        uint32_t address=registers[gpra]+registers[gprb]+signedDisplacement;
        this->pc=this->get32Memory(address);
    }
    else throw std::runtime_error("Unknown mod");
}

void Emulator::branches(uint32_t instr)
{
    uint8_t mod, gpra, gprb, gprc;  uint16_t dddd;
    mod=(instr>>24)&0xf;
    gpra=(instr>>20)&0xf;
    gprb=(instr>>16)&0xf;
    gprc=(instr>>12)&0xf;
    dddd=instr&0xfff;
    uint32_t address;
    int32_t signedDisplacement=((int32_t)(dddd<<20))>>20;

    switch(mod){
        case 0:
            this->pc=registers[gpra]+signedDisplacement;
            break;

        case 1:
            if(registers[gprb]==registers[gprc]){
                this->pc=registers[gpra]+signedDisplacement;
            }
            break;

        case 2:
            if(registers[gprb]!=registers[gprc]){
                this->pc=registers[gpra]+signedDisplacement;
            }
            break;

        case 3:
            if((int32_t)registers[gprb]>(int32_t)registers[gprc]){
                this->pc=registers[gpra]+signedDisplacement;
            }
            break;

        case 0b1000:
            address=registers[gpra]+signedDisplacement;
            this->pc=this->get32Memory(address);
            break;

        case 0b1001:
            if(registers[gprb]==registers[gprc]){
                address=registers[gpra]+signedDisplacement;
                this->pc=this->get32Memory(address);
            }
            break;

        case 0b1010:
            if(registers[gprb]!=registers[gprc]){
                address=registers[gpra]+signedDisplacement;
                this->pc=this->get32Memory(address);
            }
            break;

        case 0b1011:
            if((int32_t)registers[gprb]>(int32_t)registers[gprc]){
                address=registers[gpra]+signedDisplacement;
                this->pc=this->get32Memory(address);
            }
            break;

        default:
            throw std::runtime_error("Unknown mod");

    }

}

void Emulator::xchg(uint8_t gprb, uint8_t gprc)
{
    uint32_t tmp=registers[gprb];
    this->setRegisterVal(gprb, registers[gprc]);
    this->setRegisterVal(gprc, tmp);
}
void Emulator::aritmeticalOperations(uint32_t instr)
{
    uint8_t mod, gpra, gprb, gprc;
    mod=(instr>>24)&0xf;
    gpra=(instr>>20)&0xf;
    gprb=(instr>>16)&0xf;
    gprc=(instr>>12)&0xf;

    switch(mod){
        case 0:
            this->setRegisterVal(gpra, registers[gprb]+registers[gprc]);
            break;

        case 1:
            this->setRegisterVal(gpra, registers[gprb]-registers[gprc]);
            break;

        case 2:
            this->setRegisterVal(gpra, registers[gprb]*registers[gprc]);
            break;

        case 3:
            this->setRegisterVal(gpra, registers[gprb]/registers[gprc]);
            break;

        default:
            throw std::runtime_error("Unknown mod");
    }


}
void Emulator::logicalOperations(uint32_t instr)
{
    uint8_t mod, gpra, gprb, gprc;
    mod=(instr>>24)&0xf;
    gpra=(instr>>20)&0xf;
    gprb=(instr>>16)&0xf;
    gprc=(instr>>12)&0xf;

    switch(mod){
        case 0:
            this->setRegisterVal(gpra, ~registers[gprb]);
            break;

        case 1:
            this->setRegisterVal(gpra, registers[gprb]&registers[gprc]);
            break;

        case 2:
            this->setRegisterVal(gpra, registers[gprb]|registers[gprc]);
            break;

        case 3:
            this->setRegisterVal(gpra, registers[gprb]^registers[gprc]);
            break;

        default:
            throw std::runtime_error("Unknown mod");
    }

}
void Emulator::shiftOperations(uint32_t instr)
{
    uint8_t mod, gpra, gprb, gprc;
    mod=(instr>>24)&0xf;
    gpra=(instr>>20)&0xf;
    gprb=(instr>>16)&0xf;
    gprc=(instr>>12)&0xf;

    switch(mod){
        case 0:
            this->setRegisterVal(gpra, registers[gprb]<<registers[gprc]);
            break;

        case 1:
            this->setRegisterVal(gpra, registers[gprb]>>registers[gprc]);
            break;

        default:
            throw std::runtime_error("Unknown mod");
    }
}
void Emulator::storeOperations(uint32_t instr)
{
    uint8_t mod, gpra, gprb, gprc;
    mod=(instr>>24)&0xf;
    gpra=(instr>>20)&0xf;
    gprb=(instr>>16)&0xf;
    gprc=(instr>>12)&0xf;
    uint16_t dddd=instr&0xfff;
    uint32_t address;
    uint32_t val;
    int32_t signedDisplacement=((int32_t)(dddd<<20))>>20;

    switch(mod){
        case 0:
            val=registers[gprc];
            address=registers[gpra]+registers[gprb]+signedDisplacement;
            this->set32Memory(address, val);
            break;

        case 2:
            address=registers[gpra]+registers[gprb]+signedDisplacement;
            address=this->get32Memory(address);
            this->set32Memory(address, registers[gprc]);
            break;

        case 1:
            this->setRegisterVal(gpra, registers[gpra]+signedDisplacement);
            this->set32Memory(registers[gpra], registers[gprc]);
            break;

        default:
            throw std::runtime_error("Unknown mod");
    }

}
void Emulator::loadOperations(uint32_t instr)
{
    uint8_t mod, gpra, gprb, gprc;
    mod=(instr>>24)&0xf;
    gpra=(instr>>20)&0xf;
    gprb=(instr>>16)&0xf;
    gprc=(instr>>12)&0xf;
    uint16_t dddd=instr&0xfff;
    uint32_t address;
    int32_t signedDisplacement=((int32_t)(dddd<<20))>>20;
    
    switch (mod)
    {
        case 0:
            this->setRegisterVal(gpra, csr[gprb]);
            break;

        case 1:
            this->setRegisterVal(gpra, registers[gprb]+signedDisplacement);
            break;

        case 2:
            address=registers[gprb]+registers[gprc]+signedDisplacement;
            this->setRegisterVal(gpra, this->get32Memory(address));
            break;

        case 3:
            this->setRegisterVal(gpra, this->get32Memory(registers[gprb]));
            this->setRegisterVal(gprb, registers[gprb]+signedDisplacement);
            break;

        case 4:
            csr[gpra]=registers[gprb];
            break;

        case 5:
            csr[gpra]=csr[gprb]|dddd;
            break;

        case 6:
            address=registers[gprb]+registers[gprc]+signedDisplacement;
            csr[gpra]=this->get32Memory(address);
            break;

        case 7:
            csr[gpra]=this->get32Memory(registers[gprb]);
            this->setRegisterVal(gprb, registers[gprb]+signedDisplacement);
            break;

        default:
            throw std::runtime_error("Unknown mod");
    }
}
void Emulator::push(uint32_t val)
{
    this->sp-=4;
    this->set32Memory(this->sp, val);
}

uint32_t Emulator::pop()
{
    uint32_t ret=this->get32Memory(this->sp);
    this->sp+=4;
    return ret;
}

uint32_t Emulator::get32Memory(uint32_t address)
{
    uint32_t ret=0;
    for (size_t i = 0; i < 4; i++)
    {
        uint32_t byte=this->memory[address++] << (i * 8);
        ret |= byte;
    }
    return ret;
}

void Emulator::set32Memory(uint32_t address, uint32_t val)
{
    for (size_t i = 0; i < 4; i++)
    {
        this->memory[address++]=(val>>(i*8))&0xff;
    }
}

void Emulator::setRegisterVal(uint8_t r, uint32_t val)
{
    if(r==0) return;
    if(r>15) 
    {
        std::cout<<"Only r0-r15 exist"<<std::endl;
        exit(1);
    }
    this->registers[r] = val;
}
uint32_t Emulator::getInstruction()
{
    uint32_t instr=0;
    for (size_t i = 0; i < 4; i++)
    {
        instr<<=8;
        instr|=this->memory[this->pc++];
    }
    return instr;    
}

void Emulator::printProcessorState()
{
    for (size_t i = 0; i < 60; i++)
    {
        std::cout<<"-";
    }
    std::cout<<std::endl;
    std::cout<<"Emulated processor executed halt instruction"<<std::endl;
    std::cout<<"Emulated processor state:"<<std::endl;
    for(size_t i=0; i<16; i++){
        std::cout<<"r"<<i<<"=0x"<<std::hex<<std::setw(8)<<std::setfill('0')<<this->registers[i]<<"\t";
        if(i%4==3) std::cout<<std::endl;
    }
}
