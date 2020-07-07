#include "cursesinputhandler.h"
#include "datatypes.h"
#include <ncurses.h>

void (*up)(Game* game);
void (*down)(Game* game);
void (*left)(Game* game);
void (*right)(Game* game);
void (*pause)(Game* game);
void (*quit)(Game* game);

static void applyFunction(void (*functionPointer)(Game* game), Game* game)
{
  if (functionPointer != NULL) {
    functionPointer(game);
  }
}

void pollInput(Game* game)
{
  int ch = getch();

  if (ch == ERR) return;

  switch(ch) {
  case 'q':
    applyFunction(quit, game);
    break;
  case 'p':
    applyFunction(pause, game);
    break;
  case KEY_LEFT:
    applyFunction(left, game);
    break;
  case KEY_RIGHT:
    applyFunction(right, game);
    break;
  case KEY_UP:
    applyFunction(up, game);
    break;
  case KEY_DOWN:
    applyFunction(down, game);
    break;
  }
}

void registerUpFunction(void (*functionPointer)(Game* game))
{
  up = functionPointer;
}

void registerDownFunction(void (*functionPointer)(Game* game))
{
  down = functionPointer;
}

void registerLeftFunction(void (*functionPointer)(Game* game))
{
  left = functionPointer;
}

void registerRightFunction(void (*functionPointer)(Game* game))
{
  right = functionPointer;
}

void registerQuitFunction(void (*functionPointer)(Game* game))
{
  quit = functionPointer;
}

void registerPauseFunction(void (*functionPointer)(Game* game))
{
  pause = functionPointer;
}
