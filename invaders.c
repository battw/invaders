#include "datatypes.h"
#include "renderer.h"
#include "inputhandler.h"
#include "player.h"
#include "spaceinvader.h"
#include "collision.h"
#include <stdlib.h>
#include <unistd.h> //sleep, usleep
#include <stdio.h>

void handleVelocities(Game* game);
void handleAI(Game* game);
void handleCollisions(Game* game);
void loop(Game* game);
void gamePopulate(Game* game);
Game* gameNew();
void gamePause(Game* game);
void gameQuit(Game* game);

////////////////////////////////////////////////////////////////////////////////

void handleVelocities(Game* game)
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
  for (int id = 0; id < game->numberOfThings; ++id) {
    int collisionId = collisionPlaneCheck(game->collisionPlane,
                                          &game->collisionShapes[id],
                                          game->positions[id]);
    if (collisionId >= 0) {
      rendererDisplayMessage("HIT");
    } else {
      rendererDisplayMessage("");
    }
    collisionPlaneDraw(game->collisionPlane, &game->collisionShapes[id],
                       game->positions[id], id);
  }
  collisionPlaneClear(game->collisionPlane);
}

void loop(Game* game)
{
  gamePopulate(game);
  while (!game->isExiting) {
    inputPoll(game);
    if (game->isPaused) continue;

    render(game);
    handleVelocities(game);
    handleAI(game);
    handleCollisions(game);
  }
}

void gamePopulate(Game* game) {
  spaceInvaderSpawn(game);
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
  game->collisionShapes = calloc(game->capacity, sizeof(CollisionShape));
  
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





