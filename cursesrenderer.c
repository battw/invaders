#include "datatypes.h"
#include "renderer.h"
#include <ncurses.h>

////////////////////////////////////////////////////////////////////////////////

static bool isInBounds(int x, int y);
static void drawVisible(Game* game);
static void drawImage(int x, int y, Image *image);

////////////////////////////////////////////////////////////////////////////////

WINDOW* screen;

////////////////////////////////////////////////////////////////////////////////

void rendererStart() {
  screen = initscr();       // curses initialisation
  noecho();                 // don't echo input to the terminal
  keypad(stdscr, true);     // allow function, arrow... keys
  curs_set(0);
  raw();                    // read character data without requiring enter key
  // nodelay(stdscr, TRUE);  // prevent getch() from blocking
  halfdelay(2);
}

void rendererStop() {
  endwin();               // cleanup
}

void render(Game* game) {
  clear();
  drawVisible(game);
  refresh();
}

IntVector rendererGetSize() {
  IntVector size;
  getmaxyx(screen, size.y, size.x);
  return size;
}

////////////////////////////////////////////////////////////////////////////////

static bool isInBounds(int x, int y) {
      int maxY, maxX;
      getmaxyx(screen, maxY, maxX);
      return (y >= 0 && x >= 0 && y < maxY  && x < maxX);
}

static void drawImage(int x, int y, Image *image) {
  int imageX = x;
  int charIndex = 0;
  char ch;
  while ('\0' != (ch = (*image)[charIndex])) {
    if (ch == '\n') {
      x = imageX;
      ++y;
    } else if (ch == ' ') {
      ++x;
    } else {
      if (isInBounds(x, y)) {
        move(y, x);
        addch(ch);
      }
      ++x;
    }
    ++charIndex;
  }
}

static void drawVisible(Game* game) {
  for (int i = 0; i < game->numberOfThings; ++i) {
    if (game->areVisible[i]) {
      drawImage(game->positions[i].x, game->positions[i].y, &game->images[i]);
    }
  }
}
