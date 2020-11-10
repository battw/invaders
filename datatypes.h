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
   IntVector* coordinates;
};

struct Game {
  Image* images;
  IntVector* positions;
  IntVector* velocities;
  bool* areVisible;

  AIstate* aiStates;
  AIfunction* aiFunctions;

  CollisionPlane* collisionPlane;

  int capacity;
  int numberOfThings;
  bool isExiting;
  bool isPaused;
};

#endif
