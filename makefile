CC=gcc
CFLAGS=-I. -ggdb3 -Wall -Wextra -std=c11 
objects= invaders.o cursesrenderer.o cursesinputhandler.o collision.o player.o spaceinvader.o level.o


invaders: $(objects) 
	$(CC) -lncurses -o invaders $(objects) 

invaders.o: invaders.c renderer.h inputhandler.h collision.h player.h spaceinvader.h level.h datatypes.h
cursesrenderer.o: cursesrenderer.c renderer.h datatypes.h
cursesinputhandler.o: cursesinputhandler.c inputhandler.h datatypes.h
collision.o: collision.c collision.h datatypes.h
player.o: player.c player.h datatypes.h
spaceinvader.o: spaceinvader.c datatypes.h collision.h
level.o: level.c level.h datatypes.h

.PHONY: clean
clean:
	-rm invaders $(objects)
