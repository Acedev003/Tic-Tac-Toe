#include <cstdlib>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <limits>
#include <string>

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