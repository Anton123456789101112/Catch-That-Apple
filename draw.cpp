#include "draw.h"
#include "audio/audioManager.h"
#include "apple.h"
#include "gameLogic.h"
#include <iostream>
#include <conio.h> // For _getch()
#include <random>

extern classApple apple;


void Draw(std::string Str, int X, int Y, WORD color)
{
    HANDLE OutputH;
    COORD position = { static_cast<SHORT>(X), static_cast<SHORT>(Y) };
    OutputH = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(OutputH, color);
    SetConsoleCursorPosition(OutputH, position);
    std::cout << Str;
}

void newDraw(const std::string& str, int X, int Y, COLORREF textColor, COLORREF bgColor) 
{
    std::cout << "\x1b[" << Y + 1 << ";" << X + 1 << "H";
    int rText = GetRValue(textColor);
    int gText = GetGValue(textColor);
    int bText = GetBValue(textColor);

    int rBack = GetRValue(bgColor);
    int gBack = GetGValue(bgColor);
    int bBack = GetBValue(bgColor);
    std::cout << "\x1b[38;2;" << rText << ";" << gText << ";" << bText << "m";
    std::cout << "\x1b[48;2;" << rBack << ";" << gBack << ";" << bBack << "m";
    std::cout << str;
    std::cout << "\x1b[0m";
}

void drawRectangle(int x, int y, int height, int width, COLORREF bgColor)
{
    for(int oldX{ x - 1 }, oldY{ y }; y < height + oldY; x++)
    {
        newDraw(" ", x, y, RGB(0, 0, 0), bgColor);
        if(x == width + oldX + 1)
        {
            x = oldX;
            y++;
        }
    }
}

void drawBackground()
{
    drawRectangle(0, 31, 2, 114, RGB(52, 153, 21)); // draw grass
    drawRectangle(0, 33, 8, 114, RGB(102, 58, 24)); // draw dirt

    // Randomize darker dirt for texture
    int darkX{}, darkY{}, mediumX{}, mediumY{}, lightX{}, lightY{};

    static std::random_device rd;
    static std::mt19937 gen(rd());

    for(int i{}; i < 40; i++)
    {
        static std::uniform_int_distribution<int> distDarkX(0, 113); // 0 - 113
        darkX = distDarkX(gen);
        static std::uniform_int_distribution<int> distDarkY(33, 40);
        darkY = distDarkY(gen);

        static std::uniform_int_distribution<int> distMediumX(0, 113); 
        mediumX = distMediumX(gen);
        static std::uniform_int_distribution<int> distMediumY(33, 40); 
        mediumY = distMediumY(gen);

        static std::uniform_int_distribution<int> distLightX(0, 113); 
        lightX = distLightX(gen);
        static std::uniform_int_distribution<int> distLightY(33, 40);
        lightY = distLightY(gen);

        newDraw("  ", darkX, darkY, RGB(0, 0, 0), RGB(74, 44, 17));
        newDraw("  ", mediumX, mediumY, RGB(0, 0, 0), RGB(105, 63, 25));
        newDraw("  ", lightX, lightY, RGB(0, 0, 0), RGB(138, 91, 48));
    }

    // Draw the moon
    Draw("            ", 103, 0, 112);   
    Draw("            ", 103, 1, 112); 
    Draw("           ", 104, 2, 112); 
    Draw("         ", 106, 3, 112); 
    Draw("       ", 108, 4, 112);  
    Draw("     ", 110, 5, 112);
    Draw("  ", 113, 6, 112);

    // Moon crators
    Draw("   ", 112, 0, 128);
    newDraw("  ", 105, 1, RGB(0, 0, 0), RGB(125, 122, 120));
    newDraw("   ", 111, 3, RGB(0, 0, 0), RGB(66, 65, 64));
    newDraw("  ", 112, 4, RGB(0, 0, 0), RGB(66, 65, 64));
}

void drawMenu()
{
    stopGame();
    Sleep(1000);
    playMenu();

    // Draw menu background
    drawRectangle(37, 12, 13, 40, RGB(54, 152, 225));

    Draw("Catch That Apple!", 48, 13, 63);

    Draw("Use     to move", 39, 20, 63);
    Draw("A/D", 43, 20, 240);

    Draw("Press       to start...", 39, 22, 63);
    Draw("SPACE", 45, 22, 240);

    Draw("Choose an apple color:", 46, 16, 63);

    Draw("1", 52, 17, 79);  // Red, green txt
    Draw("2", 54, 17, 95);  // Purple, white txt 
    Draw("3", 56, 17, 207); // Light red, white txt 
    Draw("4", 58, 17, 191); // Aqua, white txt 
    Draw("5", 60, 17, 111); // Yellow, white txt 

    // Clean the buffert.
    // Otherwise it prints the default message 
    // the second time you call this function.
    while (_kbhit()) { _getch(); } 

    char val{};
    bool run { true };

    while(run)
    {
        val = _getch();

        switch (val)
        {
            case '1':
                apple.color = 79;   
                Draw("1", 52, 17, 74);  
                Draw("2", 54, 17, 95);  
                Draw("3", 56, 17, 207); 
                Draw("4", 58, 17, 191); 
                Draw("5", 60, 17, 111);
                break;
            case '2':
                apple.color = 95;
                Draw("1", 52, 17, 79);  
                Draw("2", 54, 17, 90);  
                Draw("3", 56, 17, 207); 
                Draw("4", 58, 17, 191); 
                Draw("5", 60, 17, 111);
                break;
            case '3':
                apple.color = 207;
                Draw("1", 52, 17, 79);  
                Draw("2", 54, 17, 95);  
                Draw("3", 56, 17, 202); 
                Draw("4", 58, 17, 191); 
                Draw("5", 60, 17, 111);
                break;
            case '4':
                apple.color = 191;
                Draw("1", 52, 17, 79);  
                Draw("2", 54, 17, 95);  
                Draw("3", 56, 17, 207); 
                Draw("4", 58, 17, 186); 
                Draw("5", 60, 17, 111);
                break;
            case '5':
                apple.color = 111;
                Draw("1", 52, 17, 79);  
                Draw("2", 54, 17, 95);  
                Draw("3", 56, 17, 207); 
                Draw("4", 58, 17, 191); 
                Draw("5", 60, 17, 106);
                break;
            case ' ': // Spacebar
                Beep(300,100);
                run = false;
                break;
            default:
                Beep(100,100);
                // std::cerr << "Switch Loop Fail!\n";
                break; 
        }
    }

    stopMenu();
    Sleep(1000);

    // Erase menu background
    drawRectangle(37, 12, 13, 40, RGB(12, 12, 12)); // Original shade of black

    resetGame();
    playGame();
}

