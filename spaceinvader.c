#include "datatypes.h"
#include "spaceinvader.h"
#include <stdlib.h>


static Image spaceInvaderGetImage();
enum AIstateCodes {TIMER};

#define CHANGETIME 50;


static void think(Game* game, int i) {
  int timer = --game->aiStates[i][TIMER];
  if (timer == 0) {
    game->aiStates[i][TIMER] = CHANGETIME;
    game->velocities[i].x = -game->velocities[i].x;
  }
}

void spaceInvaderSpawn(Game* game) {
  int i = game->numberOfThings++;
  game->positions[i].x = 10;
  game->positions[i].y = 10;
  game->images[i] = spaceInvaderGetImage();
  game->areVisible[i] = 1;
  game->velocities[i].x = 1;
  game->aiStates[i] = calloc(1, sizeof(int));
  game->aiStates[i][TIMER] = CHANGETIME;
  game->aiFunctions[i] = think;
}

static Image spaceInvaderGetImage() {
  /*     
         \    /
        /=0==0=\
       / ====== \
          \  /
  */
  return "  \\    /\n /=0==0=\\\n/ ====== \\\n   \\  /";
}
