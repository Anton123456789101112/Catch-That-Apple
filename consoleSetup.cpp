#include "consoleSetup.h"
#include <windows.h>

void setupConsole()
{
    SetConsoleOutputCP(CP_UTF8);  // UTF-8 (å, ä, ö)
    SetConsoleTitleW(L"🍎 Catch That Apple! 🍎");

    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

    // Change visual screen size
    SMALL_RECT windowSize = {0, 0, 114, 40}; // x1, y1, x2, y2
    SetConsoleWindowInfo(hConsole, TRUE, &windowSize);

    // Hide the annoying blinkering rectangle cursor
    CONSOLE_CURSOR_INFO cursorInfo;
    GetConsoleCursorInfo(hConsole, &cursorInfo);
    cursorInfo.bVisible = FALSE; // Change to true if you wan't it back
    SetConsoleCursorInfo(hConsole, &cursorInfo);

    
    // Disable the maximize and minimize buttons in top right corner
    // Otherwise the Draw() gets messed up when rezising
    // Does not disable resizing by dragging the edges, 
    // hence that creates a weird looking border.
    // Doesn't disable alt + tab

    HWND hwnd = GetConsoleWindow();
    LONG style = GetWindowLong(hwnd, GWL_STYLE);
    style &= ~WS_MAXIMIZEBOX;
    style &= ~WS_MINIMIZEBOX;
    SetWindowLong(hwnd, GWL_STYLE, style);
    SetWindowPos(hwnd, NULL, 0, 0, 0, 0,
                 SWP_NOMOVE | SWP_NOSIZE | SWP_NOZORDER | SWP_FRAMECHANGED);

    // Enable ANSI-mode for newDraw()
    // Windows 10+
    HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    DWORD dwMode = 0;
    GetConsoleMode(hOut, &dwMode);
    dwMode |= ENABLE_VIRTUAL_TERMINAL_PROCESSING;
    SetConsoleMode(hOut, dwMode);

}
