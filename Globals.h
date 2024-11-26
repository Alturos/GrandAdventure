#pragma once
//Globals.h
#ifndef GLOBALS_H
#define GLOBALS_H

#include <iostream>
#include <string>
//#include "lvprandom.h"
#include "fmod.hpp"
//#include "Console.h"
//namespace con=JadedHoboConsole;
//using namespace con;
using namespace std;

namespace Globals {

extern const char* fg_black;
extern const char* fg_red;
extern const char* fg_green;
extern const char* fg_yellow;
extern const char* fg_blue;
extern const char* fg_magenta;
extern const char* fg_cyan;
extern const char* fg_white;

extern const char* fg_brightblack;
extern const char* fg_brightred;
extern const char* fg_brightgreen;
extern const char* fg_brightyellow;
extern const char* fg_brightblue;
extern const char* fg_brightmagenta;
extern const char* fg_brightcyan;
extern const char* fg_brightwhite;

extern const char* bg_black;
extern const char* bg_red;
extern const char* bg_green;
extern const char* bg_yellow;
extern const char* bg_blue;
extern const char* bg_magenta;
extern const char* bg_cyan;
extern const char* bg_white;

extern const char* bg_gray;

inline std::ostream& clr( std::ostream& os )
{
    os.flush();
    system("clear");
    return os;
};

inline void _getch()
{
    fflush(stdin);
	getchar();
}

inline void _getche()
{
    fflush(stdin);
	getchar();
}
}

#endif
