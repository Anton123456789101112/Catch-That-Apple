#include "timers.h"

void classTimers::updateTimers()
{
    playerTimer2 = GetTickCount();                             
    playerElapsed =  playerTimer2 - playerTimer1;   
    appleTimer2 = GetTickCount();                             
    appleElapsed =  appleTimer2 - appleTimer1;
    gameDiffTimer2 = GetTickCount();                             
    gameDiffElapsed =  gameDiffTimer2 - gameDiffTimer1;
}

void classTimers::startTimers()
{
    playerTimer1 = GetTickCount();
    appleTimer1 = GetTickCount();
    gameDiffTimer1 = GetTickCount();
}

void classTimers::resetPlayerTimer()
{
    playerTimer1 = GetTickCount();
    playerElapsed = 0;   
}

void classTimers::resetAppleTimer()
{
    appleTimer1 = GetTickCount();
    appleElapsed = 0;
}

void classTimers::resetGameDiffTimer()
{
    gameDiffTimer1 = GetTickCount();
    gameDiffElapsed = 0;
}




