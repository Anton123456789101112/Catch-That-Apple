#include "player.h"
#include "draw.h"

void classPlayer::moveRight()  { x++; }
void classPlayer::moveLeft()   { x--; }

void classPlayer::drawP()
{
    Draw("  ", x, y - 4, 128);
    Draw("  ", x, y - 3, 128);
    Draw("  ", x, y - 2, 128);
    Draw("  ", x, y - 1, 128);
    Draw("       ", x + 1, y, 128);
    Draw("  ", x + 7, y - 4, 128);
    Draw("  ", x + 7, y - 3, 128);
    Draw("  ", x + 7, y - 2, 128);
    Draw("  ", x + 7, y - 1, 128);
}

void classPlayer::eraseP()
{
    Draw("  ", x, y - 4, 0);
    Draw("  ", x, y - 3, 0);
    Draw("  ", x, y - 2, 0);
    Draw("  ", x, y - 1, 0);
    Draw("       ", x + 1, y, 0);
    Draw("  ", x + 7, y - 4, 0);
    Draw("  ", x + 7, y - 3, 0);
    Draw("  ", x + 7, y - 2, 0);
    Draw("  ", x + 7, y - 1, 0);
}

