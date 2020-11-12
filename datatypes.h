#ifndef DATATYPES_INCLUDED
#define DATATYPES_INCLUDED

#include <stdbool.h>

////////////////////////////////////////////////////////////////////////////////
typedef char* Image;

struct IntVector;
typedef struct IntVector IntVector;


////////////////////////////////////////////////////////////////////////////////
struct Game;
typedef struct Game Game;


////////////////////////////////////////////////////////////////////////////////
struct CollisionPlane;
typedef struct CollisionPlane CollisionPlane;


struct CollisionShape;
typedef struct CollisionShape CollisionShape;

typedef void (*CollisionFunction)(Game* game, int id);

////////////////////////////////////////////////////////////////////////////////
typedef int* AIstate;
typedef void (*AIfunction)(Game* game, int id);


////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////

struct IntVector {
  int x;
  int y;
};

struct CollisionPlane {
  IntVector size;
  int* plane;
};

struct CollisionShape {
  int length;
  IntVector* coordinates;
};

struct Game {
  Image* images;
  IntVector* positions;
  IntVector* velocities;
  bool* areVisible;
  bool* areAlive;

  AIstate* aiStates;
  AIfunction* aiFunctions;

  CollisionPlane* collisionPlane;
  CollisionShape* collisionShapes;
  CollisionFunction* collisionFunctions;

  int capacity;
  int numberOfThings;
  bool isExiting;
  bool isPaused;
};

#endif // DATATYPES_INCLUDED
