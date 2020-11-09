#ifndef RENDERER_INCLUDED
#define RENDERER_INCLUDED

#include "datatypes.h"

void rendererStart();
void rendererStop();
void render(Game* game);
IntVector rendererGetSize();

#endif
