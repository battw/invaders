#include "level.h"
#include "spaceinvader.h"

////////////////////////////////////////////////////////////////////////////////
static void level1(Game* game);

////////////////////////////////////////////////////////////////////////////////
void (*levelFunctions[])(Game* game) = {level1};

////////////////////////////////////////////////////////////////////////////////
void level(Game* game, int n) {
    levelFunctions[n-1](game);
}

void level1(Game* game) {
    IntVector spawnPosition;
    spawnPosition.y = 10;
    spawnPosition.x = 10;
    int spacing = 30;
    while (spawnPosition.x < game->playArea.x - 30) {
        spaceInvaderSpawn(game, spawnPosition);
        spawnPosition.x += spacing;
    }
}
