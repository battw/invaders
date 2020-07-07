#include "datatypes.h"
#include "cursesrenderer.h"
#include "cursesinputhandler.h"
#include <stdlib.h>
#include <unistd.h> //sleep, usleep

Image getShipImage();
void loop(Game* game);

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
  float sleepTime = 3; 
  bool running = 1;
  while (running) {
    render(game);
    //applyVelocities(game);
    sleep(sleepTime);
    running = 0;
  }
}

void addPlayerShip(Game* game) {
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

int main()
{
  startRenderer();
  Game* game = newGame();
  loop(game);

  stopRenderer();
  return 0;
}





