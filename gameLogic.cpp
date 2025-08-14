#include "gameLogic.h"
#include "audio/audioManager.h"
#include "draw.h"
#include "player.h"
#include "apple.h"
#include "timers.h"
#include <iostream>

extern classPlayer player;
extern classTimers timer;
extern classApple apple;
extern classGameState gameState;

void classGameState::updateScore()
{
    // Erase old score
    Draw("       ", 1, 1, 0);

    classGameState::score++;

    // Draw new score
    Draw("  ", 1, 1, apple.color);
    Draw(": ", 3, 1, 15);
    std::cout << classGameState::score;
}

void updateApple()
{
    if(timer.appleElapsed > timer.gameDiff)
    {
        apple.eraseA();
        apple.fall();
        apple.drawA();
        timer.resetAppleTimer();
    }
}

void checkAppleCollision()
{
    // If apple is caught by the basket
    if((apple.y + 2 > player.y - 3) && (apple.x > player.x) && (apple.x < player.x + 6))
    {
        gameState.updateScore();
        playCrunch();
        apple.eraseA();
        apple.respawn();
    }
    // If apple hits the ground / Game Over
    else if(apple.y + 2 == 30)
    {
        stopGame();
        Sleep(50);
        playGrass();
        Sleep(1000);

        drawMenu();
    }
}

void increaseGameDiff()
{
    if((timer.gameDiffElapsed > 2500) && (timer.gameDiff > 10))
    {
        timer.gameDiff -= 5;
        timer.resetGameDiffTimer();
    }
}

void resetGame()
{
    gameState.score = 0;
    gameState.updateScore();
    apple.eraseA();
    apple.respawn();
    timer.gameDiff = 100;
    // Reset timers?
}




