#pragma once
#include <string>

#ifdef __linux__ 
    #define CLS "clear"
#elif _WIN32
    #define CLS "cls"
#endif

void reset_screen(); 
void press_enter_to_continue();
void logging(std::string msg);

bool cin_failed();
bool read_int(int& val);