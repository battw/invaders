#include "inputhandler.h"
#include "datatypes.h"
#include <ncurses.h>

void (*up)(Game* game);
void (*down)(Game* game);
void (*left)(Game* game);
void (*right)(Game* game);
void (*pause)(Game* game);
void (*quit)(Game* game);

static void applyFunction(void (*functionPointer)(Game* game), Game* game);

////////////////////////////////////////////////////////////////////////////////

void inputInit(void (*playerUp)(Game* game)
                      , void (*playerDown)(Game* game)
                      , void (*playerLeft)(Game* game)
                      , void (*playerRight)(Game* game)
                      , void (*gamePause)(Game* game)
                      , void (*gameQuit)(Game* game)
) {

  up = playerUp;
  down = playerDown;
  left = playerLeft;
  right = playerRight;
  pause = gamePause;
  quit = gameQuit;
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


////////////////////////////////////////////////////////////////////////////////

static void applyFunction(void (*functionPointer)(Game* game), Game* game)
{
  if (functionPointer != NULL) {
    functionPointer(game);
  }
}
