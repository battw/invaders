#ifndef RENDERER_INCLUDED
#define RENDERER_INCLUDED

#include "datatypes.h"

void rendererInit();
void rendererDeinit();
void render(Game* game);
IntVector rendererGetSize();
void rendererDisplayMessage(char* msg);

#endif
