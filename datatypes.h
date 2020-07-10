#ifndef DATATYPES_INCLUDED
#define DATATYPES_INCLUDED

struct Game;

typedef struct Game Game;

typedef char bool;

typedef char* Image;

struct IntVector {
  int x;
  int y;
};
typedef struct IntVector IntVector;

typedef int* AIstate;
typedef void (*AIfunction)(Game* game, int id);


struct Game {
  Image* images;
  IntVector* positions;
  IntVector* velocities;
  bool* areVisible;

  AIstate* aiStates;
  AIfunction* aiFunctions;

  int capacity;
  int numberOfThings;
  bool isExiting;
  bool isPaused;
};

#endif
