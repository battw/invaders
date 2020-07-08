#include "datatypes.h"
#include "renderer.h"
#include "inputhandler.h"
#include <stdlib.h>
#include <unistd.h> //sleep, usleep

Image newShipImage();
void applyVelocities(Game* game);
void loop(Game* game);
void addPlayerShip(Game* game);
Game* newGame();

void inputHandlerInit();
void inputUp(Game* game);
void inputDown(Game* game);
void inputLeft(Game* game);
void inputRight(Game* game);
void inputPause(Game* game);
void inputQuit(Game* game);

////////////////////////////////////////////////////////////////////////////////

Image newShipImage()
{
  /*
          |
          O
          O
         OOO
        OOOOO
        ^ ^ ^
  */
  return "  |\n  O\n  O\n OOO \nOOOOO\n^ ^ ^\n";
}

void applyVelocities(Game* game)
{
  for (int i = 0; i < game->numberOfThings; ++i) {
    game->positions[i].x += game->velocities[i].x;
    game->positions[i].y += game->velocities[i].y;
  }
}

void loop(Game* game)
{
  while (!game->isExiting) {
    pollInput(game);
    if (game->isPaused) continue;

    render(game);
    applyVelocities(game);
  }
}

void addPlayerShip(Game* game)
{
  game->positions[0].x = 10;
  game->positions[0].y = 20;
  game->images[0] = newShipImage();
  game->areVisible[0] = 1;
}

Game* newGame()
{
  Game* game = calloc(1, sizeof(Game));
  game->numberOfThings = 1;

  game->positions = calloc(game->numberOfThings, sizeof(IntVector));
  game->velocities = calloc(game->numberOfThings, sizeof(IntVector));
  game->images = calloc(game->numberOfThings, sizeof(Image*));
  game->areVisible = calloc(game->numberOfThings, sizeof(bool));
  
  addPlayerShip(game);
  return game;
}


void inputUp(Game* game)
{
  --game->velocities[0].y;
}

void inputDown(Game* game)
{
  ++game->velocities[0].y;
}
void inputLeft(Game* game)
{
  --game->velocities[0].x;
}
void inputRight(Game* game)
{
  ++game->velocities[0].x;
}
void inputPause(Game* game)
{
  game->isPaused = !game->isPaused;
}

void inputQuit(Game* game) {
  game->isExiting = 1;
}

void inputHandlerInit()
{
  registerUpFunction(inputUp);
  registerDownFunction(inputDown);
  registerLeftFunction(inputLeft);
  registerRightFunction(inputRight);
  registerPauseFunction(inputPause);
  registerQuitFunction(inputQuit);
}

int main()
{
  inputHandlerInit();
  rendererStart();

  Game* game = newGame();
  loop(game);
  
  rendererStop();
  return 0;
}





