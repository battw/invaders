#include "inputhandler.h"
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

void inputPoll(Game* game)
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

void inputSetUpCallback(void (*functionPointer)(Game* game))
{
  up = functionPointer;
}

void inputSetDownCallback(void (*functionPointer)(Game* game))
{
  down = functionPointer;
}

void inputSetLeftCallback(void (*functionPointer)(Game* game))
{
  left = functionPointer;
}

void inputSetRightCallback(void (*functionPointer)(Game* game))
{
  right = functionPointer;
}

void inputSetQuitCallback(void (*functionPointer)(Game* game))
{
  quit = functionPointer;
}

void inputSetPauseCallback(void (*functionPointer)(Game* game))
{
  pause = functionPointer;
}
