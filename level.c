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
    IntVector position;
    position.y = 5;
    position.x = 10;
    int spacing = 30;
    for (int i = 0; i < 7; i++) {
        spaceInvaderSpawn(game, position);
        position.x += spacing;
    }
}
