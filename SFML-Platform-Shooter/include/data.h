#ifndef DATA_INCLUDED
#define DATA_INCLUDED
#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#if defined(_WIN32)
#if defined(_MSC_VER)
#include <Windows.h>
#else
#include <windows.h>
#endif
#elif defined(__linux__)
#include <unistd.h>
#define Sleep(m) usleep(m * 1000)
#endif
#define kb Keyboard

using namespace sf;

enum Direction
{
   Still = 0, Up = 1, Down = 2, Left = 3, Right = 4
};
#endif
