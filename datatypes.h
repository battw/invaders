#ifndef DATATYPES_INCLUDED
#define DATATYPES_INCLUDED

typedef char bool;

typedef char* Image;

struct IntVector {
  int x;
  int y;
};
typedef struct IntVector IntVector;

struct Game {
  Image* images;
  IntVector* positions;
  IntVector* velocities;
  bool* areVisible;
  int numberOfThings;
};
typedef struct Game Game;

#endif
