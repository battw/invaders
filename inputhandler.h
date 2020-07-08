#ifndef INPUTHANDLER_INCLUDED
#define INPUTHANDLER_INCLUDED

#include "datatypes.h"

void pollInput(Game* game);
void registerUpFunction(void (*functionPointer)(Game* game));
void registerDownFunction(void (*functionPointer)(Game* game));
void registerLeftFunction(void (*functionPointer)(Game* game));
void registerRightFunction(void (*functionPointer)(Game* game));
void registerQuitFunction(void (*functionPointer)(Game* game));
void registerPauseFunction(void (*functionPointer)(Game* game));

#endif
                                
