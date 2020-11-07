#include "datatypes.h"
#include "renderer.h"
#include "inputhandler.h"
#include "player.h"
#include "spaceinvader.h"
#include <stdlib.h>
#include <unistd.h> //sleep, usleep

void applyVelocities(Game* game);
void loop(Game* game);
Game* newGame();
void inputHandlerInit();
void moveUp(Game* game);
void moveDown(Game* game);
void moveLeft(Game* game);
void moveRight(Game* game);
void pauseGame(Game* game);
void quitGame(Game* game);

////////////////////////////////////////////////////////////////////////////////



void applyVelocities(Game* game)
{
  for (int i = 0; i < game->numberOfThings; ++i) {
    game->positions[i].x += game->velocities[i].x;
    game->positions[i].y += game->velocities[i].y;
  }
}

void handleAI(Game* game) {
  for (int i = 0; i < game->numberOfThings; ++i) {
    if (game->aiFunctions[i] != NULL) {
      game->aiFunctions[i](game, i);
    }
  }
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
  }
}


Game* newGame()
{
  Game* game = calloc(1, sizeof(Game));

  game->capacity = 256;
  game->numberOfThings = 0;
  game->isExiting = 0;
  game->isPaused = 0;
  game->positions = calloc(game->capacity, sizeof(IntVector));
  game->velocities = calloc(game->capacity, sizeof(IntVector));
  game->images = calloc(game->capacity, sizeof(Image));
  game->areVisible = calloc(game->capacity, sizeof(bool));
  game->aiStates = calloc(game->numberOfThings, sizeof(AIstate));
  game->aiFunctions = calloc(game->numberOfThings, sizeof(AIfunction));

  playerSpawn(game);
  return game;
}


void playerUp(Game* game)
{
  --game->velocities[0].y;
}

void playerDown(Game* game)
{
  ++game->velocities[0].y;
}
void playerLeft(Game* game)
{
  --game->velocities[0].x;
}
void playerRight(Game* game)
{
  ++game->velocities[0].x;
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
  inputInit(playerUp, playerDown, playerLeft, playerRight, gamePause, gameQuit);
  rendererStart();

  Game* game = newGame();
  loop(game);
  
  rendererStop();
  return 0;
}





