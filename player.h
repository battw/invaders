#ifndef PLAYER_INCLUDED
#define PLAYER_INCLUDED

#include "datatypes.h"

void playerSpawn(Game* game);

void playerUp(Game* game);
void playerDown(Game* game);
void playerLeft(Game* game);
void playerRight(Game* game);
void playerFire(Game* game);

void playerCollide(Game* game, int id);

#endif // PLAYER_INCLUDED
