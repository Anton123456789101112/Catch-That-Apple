#pragma once
#include "draw.h"

class classPlayer
{
public:
    int x{ 53 };
    int y{ 30 };

    void moveRight();
    void moveLeft();
    void drawP();
    void eraseP();
};
