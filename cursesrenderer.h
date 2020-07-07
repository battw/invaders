#ifndef CURSES_INCLUDED
#define CURSES_INCLUDED

#include "datatypes.h"

void startRenderer();
void stopRenderer();
void render(Game* game);

#endif
