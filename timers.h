#pragma once
#include <windows.h>

class classTimers
{
public:
    DWORD playerTimer1{};
    DWORD playerTimer2{};
    DWORD playerElapsed{};

    DWORD appleTimer1{};
    DWORD appleTimer2{};
    DWORD appleElapsed{};

    DWORD gameDiffTimer1{};
    DWORD gameDiffTimer2{};
    DWORD gameDiffElapsed{};

    DWORD gameDiff { 100 };

    void updateTimers();
    void startTimers();
    void resetPlayerTimer();
    void resetAppleTimer();
    void resetGameDiffTimer();
};
