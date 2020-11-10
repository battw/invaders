#include "datatypes.h"
#include "renderer.h"
#include "inputhandler.h"
#include "player.h"
#include "spaceinvader.h"
#include "collision.h"
#include <stdlib.h>
#include <unistd.h> //sleep, usleep

void applyVelocities(Game* game);
void loop(Game* game);
Game* newGame();
void gamePause(Game* game);
void gameQuit(Game* game);

////////////////////////////////////////////////////////////////////////////////

void applyVelocities(Game* game)
{
  for (int i = 0; i < game->numberOfThings; ++i) {
    game->positions[i].x += game->velocities[i].x;
    game->positions[i].y += game->velocities[i].y;
  }
}

void handleAI(Game* game)
{
  for (int i = 0; i < game->numberOfThings; ++i) {
    if (game->aiFunctions[i] != NULL) {
      game->aiFunctions[i](game, i);
    }
  }
}

void handleCollisions(Game* game)
{
  rendererDisplayMessage("collisions");
}

void loop(Game* game)
{
  spaceInvaderSpawn(game);
  while (!game->isExiting) {
    inputPoll(game);
    if (game->isPaused) continue;

    render(game);
    applyVelocities(game);
    handleAI(game);
    handleCollisions(game);
  }
}

Game* gameNew()
{
  Game* game = calloc(1, sizeof(Game));

  game->capacity = 256;
  game->numberOfThings = 1;
  game->isExiting = 0;
  game->isPaused = 0;
  game->positions = calloc(game->capacity, sizeof(IntVector));
  game->velocities = calloc(game->capacity, sizeof(IntVector));
  game->images = calloc(game->capacity, sizeof(Image));
  game->areVisible = calloc(game->capacity, sizeof(bool));
  game->aiStates = calloc(game->numberOfThings, sizeof(AIstate));
  game->aiFunctions = calloc(game->numberOfThings, sizeof(AIfunction));
  game->collisionPlane = collisionPlaneNew(rendererGetSize());

  playerSpawn(game);
  return game;
}

void gamePause(Game* game)
{
  game->isPaused = !game->isPaused;
}

void gameQuit(Game* game) {
  game->isExiting = 1;
}

int main()
{
  rendererStart();
  inputInit(playerUp, playerDown, playerLeft, playerRight, gamePause, gameQuit);

  Game* game = gameNew();
  loop(game);
  rendererStop();
  return 0;
}





