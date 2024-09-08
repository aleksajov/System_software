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

    int stat=emulator.readExecutableFile(argv[1]);
    if(stat) return stat;

    return 0;
}
int Emulator::readExecutableFile(std::string file)
{
    std::ifstream in(file);
    if(!in)
    {
        std::cout<<"Error opening file "<<file<<std::endl;
        return 1;
    }

    std::regex lineRegex("([a-fA-F0-9]{8}):\\s+([a-fA-F0-9]{2}\\s+){0,8}");
    std::string line;
    while(std::getline(in, line)){
        std::smatch match;
        if(std::regex_search(line, match, lineRegex)){
            uint32_t address=std::stoul(match.str(1), nullptr, 16);
            std::vector<uint8_t> bytes;
            for (size_t i = 2; i < match.size(); ++i) {
                if (match.str(i).empty()) break;
                uint8_t byte = std::stoul(match.str(i), nullptr, 16);
                bytes.push_back(byte);
            }
            std::cout<<std::hex<<std::setw(8)<<std::setfill('0')<<address<<": ";
            for(auto byte: bytes)
            {
                std::cout<<std::hex<<std::setw(2)<<std::setfill('0')<<(int)byte<<" ";
            }
            
        }
        else{
            std::cout<<"Executable file not in correct format"<<std::endl;
            return 1;
        }
        std::cout<<std::endl;
    }


    in.close();
    return 0;
}