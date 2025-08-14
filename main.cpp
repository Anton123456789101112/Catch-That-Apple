#include "apple.h"
#include "player.h"
#include "timers.h"
#include "gameLogic.h"
#include "audio/audioManager.h"
#include "inputManager.h"
#include "draw.h"
#include "consoleSetup.h"


// Global - bad :P :O :D
classApple apple;
classPlayer player;
classTimers timer;
classGameState gameState;

int main()
{
    if (!initAudioEngine())
        return -1;

    setupConsole();
    player.drawP();
    drawBackground();

    drawMenu();
    srand(GetTickCount());
    timer.startTimers();
    
    // Game Loop
    while(true)
    {
        timer.updateTimers();
        increaseGameDiff();
        checkAppleCollision();
        updateApple();
        handleInput();
    }

    // Game game;
    // game.run();

    uninitAudioEngine();
    return 0;
}
