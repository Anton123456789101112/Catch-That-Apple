#pragma once 
#include <windows.h>

class classApple
{
public:
    int x{};
    int y{};
    WORD color { 79 };

    void fall();
    void respawn();
    void drawA();
    void eraseA();
    
};
