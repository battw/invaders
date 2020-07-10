#ifndef INPUTHANDLER_INCLUDED
#define INPUTHANDLER_INCLUDED

#include "datatypes.h"

void inputPoll(Game* game);
void inputSetUpCallback(void (*functionPointer)(Game* game));
void inputSetDownCallback(void (*functionPointer)(Game* game));
void inputSetLeftCallback(void (*functionPointer)(Game* game));
void inputSetRightCallback(void (*functionPointer)(Game* game));
void inputSetQuitCallback(void (*functionPointer)(Game* game));
void inputSetPauseCallback(void (*functionPointer)(Game* game));

#endif
                                
