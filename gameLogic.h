#pragma once

void updateApple();
void checkAppleCollision();
void increaseGameDiff();
void resetGame();

class classGameState
{
public:
    int score{};

    void updateScore();

};
