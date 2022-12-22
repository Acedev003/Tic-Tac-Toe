#include <cstdlib>
#include <cstdio>
#include <iostream>
#include <fstream>
#include <sstream>
#include <limits>
#include <string>
#include <chrono>

#include "util.hpp"

void reset_screen()
{
    system(CLS);
    printf("\n -- Tic Tac Toe -- \n\n");
}

bool read_int(int& val)
{
    std::string buf;
    std::getline(std::cin,buf);
    for(auto character : buf)
    {
        switch (character)
        {
            case '0':
            case '1':
            case '2':
            case '3':
            case '4':
            case '5':
            case '6':
            case '7':
            case '8':
            case '9':
                      break;
            default : return false;
        }
    }

    try
    {
        val = std::stoi(buf);
        return true;
    }
    catch(const std::exception& e)
    {
        return false;
    }
    
}

void press_enter_to_continue()
{
    std::cin.clear();
    std::cout<<"Press Enter to continue";
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
}

bool cin_failed()
{
    bool state = std::cin.fail();
    std::cin.clear();
    return state;  
}


void logging(std::string msg)
{
    std::ofstream file("LOG.txt",std::ios_base::app);
    
    typedef std::chrono::system_clock clock;

    auto now = clock::now();
    auto seconds = std::chrono::time_point_cast<std::chrono::seconds>(now);
    auto fraction = now - seconds;
    std::time_t cnow = clock::to_time_t(now);
    auto milliseconds = std::chrono::duration_cast<std::chrono::milliseconds>(fraction);

    char time_str[100];
    if (std::strftime(time_str, sizeof(time_str), "%H:%M:%S.", std::localtime(&cnow))) 
    {
        file << time_str << milliseconds.count()<<":";
    }

    file<<msg<<"\n";
    file.close();
}