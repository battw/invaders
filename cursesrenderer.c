#include "datatypes.h"
#include "cursesrenderer.h"
#include <ncurses.h>


void rendererStart() {
  initscr();              // curses initialisation
  noecho();               // don't echo input to the terminal
  keypad(stdscr, true);   // allow function, arrow... keys
  curs_set(0);
  raw();		  // read character data without requiring enter key
  //nodelay(stdscr, TRUE);  // prevent getch() from blocking
  halfdelay(2);
}

void rendererStop() {
  endwin();               // cleanup
}

static void drawImage(int x, int y, Image *image) {
  int minX = x;
  int charIndex = 0;
  char ch;
  while ('\0' != (ch = (*image)[charIndex])) {
    if (ch == '\n') {
      x = minX;
      ++y;
    } else if (ch == ' ') {
      ++x;
    } else {
      move(y, x);
      addch(ch);
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
                        
void render(Game* game) {
  clear();
  drawVisible(game);
  refresh();
}
