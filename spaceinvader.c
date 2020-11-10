#include "spaceinvader.h"
#include "datatypes.h"
#include "collision.h"

#include <stdlib.h>


static Image spaceInvaderGetImage();
static CollisionShape* spaceInvaderGetCollisionShape();
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
  int id = game->numberOfThings++;
  game->positions[id].x = 10;
  game->positions[id].y = 10;
  game->images[id] = spaceInvaderGetImage();
  game->areVisible[id] = 1;
  game->velocities[id].x = 1;
  game->aiStates[id] = calloc(1, sizeof(int));
  game->aiStates[id][TIMER] = CHANGETIME;
  game->aiFunctions[id] = think;
  game->collisionShapes[id] = *spaceInvaderGetCollisionShape();
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

static CollisionShape* spaceInvaderGetCollisionShape() {
  IntVector size = {10, 5};
  IntVector coordinates[size.x * size.y];
  for (int x = 0; x < size.x; x++) {
    for (int y = 0; y < size.y; y++) {
      int i = size.x * y + x;
      coordinates[i].x = x;
      coordinates[i].y = y;
    }
  }

  return collisionShapeNew(size.x * size.y, coordinates);
}
