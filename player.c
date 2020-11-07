#include "player.h"

static Image playerGetImage();

////////////////////////////////////////////////////////////////////////////////

void playerSpawn(Game* game)
{
  // TODO spawn position should take into account window size.
  game->positions[0].x = 120;
  game->positions[0].y = 45;
  game->images[0] = playerGetImage();
  game->areVisible[0] = 1;
  // TODO this might increment past the capacity of the game.
  ++game->numberOfThings;
}

static Image playerGetImage()
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
