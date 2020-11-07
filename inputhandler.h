#ifndef INPUTHANDLER_INCLUDED
#define INPUTHANDLER_INCLUDED

#include "datatypes.h"

void inputInit(void (*up)(Game* game)
                      , void (*down)(Game* game)
                      , void (*left)(Game* game)
                      , void (*right)(Game* game)
                      , void (*pause)(Game* game)
                      , void (*quit)(Game* game)
);

void inputPoll(Game* game);

#endif
                                
