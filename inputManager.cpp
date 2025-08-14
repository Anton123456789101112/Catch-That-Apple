#include "inputManager.h"
#include "player.h"
#include "timers.h"
#include <windows.h>

extern classPlayer player;
extern classTimers timer;

void handleInput()
{
    if(GetAsyncKeyState(0x41) && (timer.playerElapsed > 10) && (player.x > 7)) // A
    {
        player.eraseP();
        player.moveLeft();
        player.drawP();
        timer.resetPlayerTimer();

    }
    else if(GetAsyncKeyState(0x44) && (timer.playerElapsed > 10) && (player.x < 99)) // D
    {
        player.eraseP();
        player.moveRight();
        player.drawP();
        timer.resetPlayerTimer();
    }
}
