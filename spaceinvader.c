#include "spaceinvader.h"
#include "datatypes.h"
#include "collision.h"

#include <stdlib.h>


static Image spaceInvaderGetImage();
static CollisionShape* spaceInvaderGetCollisionShape();
enum AIstateCodes {TIMER};

#define CHANGETIME 30;


static void think(Game* game, int id) {
  if (!game->areAlive[id]) return;

  int timer = --game->aiStates[id][TIMER];
  if (timer == 0) {
    game->aiStates[id][TIMER] = CHANGETIME;
    game->velocities[id].x = -game->velocities[id].x;
  }
}

void spaceInvaderSpawn(Game* game, IntVector position) {
  if (game->capacity <= game->numberOfThings)
    return;

  int id = game->numberOfThings++;

  game->images[id] = spaceInvaderGetImage();
  game->positions[id] = position;
  game->velocities[id].x = 1;

  game->areVisible[id] = true;
  game->areAlive[id] = true;

  game->aiStates[id] = calloc(1, sizeof(int));
  game->aiStates[id][TIMER] = CHANGETIME;
  game->aiFunctions[id] = think;

  game->collisionShapes[id] = *spaceInvaderGetCollisionShape();
  game->collisionFunctions[id] = spaceInvaderCollide;
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

void spaceInvaderCollide(Game* game, int id) {
  game->images[id] = "##########\n##########\n##########\n##########\n##########\n";
  game->areAlive[id] = false;
}
