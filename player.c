#include "player.h"
#include "datatypes.h"
#include "collision.h"

static Image playerGetImage();
static CollisionShape* playerGetCollisionShape();

////////////////////////////////////////////////////////////////////////////////

void playerSpawn(Game* game)
{
  // TODO spawn position should take into account window size.
  game->positions[0].x = 120;
  game->positions[0].y = 45;
  game->images[0] = playerGetImage();
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


static CollisionShape* playerGetCollisionShape() {
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

void playerCollide(Game* game, int id) {
  game->images[id] = "#####\n#####\n#####\n#####\n#####\n#####\n";
  game->areAlive[id] = false;
}
