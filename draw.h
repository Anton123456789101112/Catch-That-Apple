#pragma once
#include <string>
#include <windows.h>

void Draw(std::string Str, int X, int Y, WORD color);

// Works with many more colors
void newDraw(const std::string& str, int X, int Y, COLORREF textColor, COLORREF bgColor);

// x and y is the pos of top left corner
void drawRectangle(int x, int y, int height, int width, COLORREF bgColor);

void drawBackground();

void drawMenu();



