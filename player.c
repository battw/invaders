#include "player.h"
#include "datatypes.h"
#include "collision.h"

#include <stdlib.h>

static Image playerGetImage();
static CollisionShape* playerGetCollisionShape();

////////////////////////////////////////////////////////////////////////////////

void playerSpawn(Game* game)
{
  game->images[0] = playerGetImage();
  game->positions[0].x = 120;
  game->positions[0].y = 45;

  game->areVisible[0] = true;
  game->areAlive[0] = true;

  game->collisionShapes[0] = *playerGetCollisionShape();
  game->collisionFunctions[0] = playerCollide;
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


static CollisionShape* playerGetCollisionShape()
{
  IntVector size = {5, 6};
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

void playerUp(Game* game)
{
  if (game->areAlive[0])
    --game->velocities[0].y;
}

void playerDown(Game* game)
{
  if (game->areAlive[0])
    ++game->velocities[0].y;
}
void playerLeft(Game* game)
{
  if (game->areAlive[0])
    --game->velocities[0].x;
}
void playerRight(Game* game)
{
  if (game->areAlive[0])
    ++game->velocities[0].x;
}

void playerCollide(Game* game, int id)
{
  game->images[id] = "#####\n#####\n#####\n#####\n#####\n#####\n";
  game->areAlive[id] = false;
}

void playerFire(Game* game) {
  if (game->capacity <= game->numberOfThings)
    return;

  int id = game->numberOfThings++;

  game->images[id] = "*\n";

  game->positions[id] = game->positions[0];
  game->positions[id].x += 2;
  game->positions[id].y -= 1;

  game->velocities[id] = game->velocities[0];
  game->velocities[id].y -= 1;

  game->areVisible[id] = true;
  game->areAlive[id] = true;

  IntVector* collisionCoordinates = calloc(1, sizeof(IntVector));
  game->collisionShapes[id] = *collisionShapeNew(1, collisionCoordinates);
}
