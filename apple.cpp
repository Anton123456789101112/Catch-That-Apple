#include "apple.h"
#include "draw.h"
#include <random>

void classApple::fall() { y++; }

void classApple::respawn()
{
    y = 1;

    static std::random_device rd;
    static std::mt19937 gen(rd());
    static std::uniform_int_distribution<int> dist(10, 101); // 10 - 101
    x = dist(gen);
}

void classApple::drawA()
{
    Draw(" ", x + 1, y, 32);
    Draw("   ", x, y + 1, classApple::color);
    Draw("   ", x, y + 2, classApple::color);
}
void classApple::eraseA()
{
    Draw(" ", x + 1, y, 0);
    Draw("   ", x, y + 1, 0);
    Draw("   ", x, y + 2, 0);
}





