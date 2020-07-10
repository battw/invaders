CC=gcc
CFLAGS=-I. -ggdb3 -Wall -Wextra -std=c11 
objects= invaders.o cursesrenderer.o cursesinputhandler.o spaceinvader.o


invaders: $(objects) 
	$(CC) -lncurses -o invaders $(objects) 

invaders.o: invaders.c datatypes.h renderer.h inputhandler.h spaceinvader.h
cursesrenderer.o: cursesrenderer.c renderer.h datatypes.h
cursesinputhandler.o: cursesinputhandler.c inputhandler.h datatypes.h
spaceinvader.o: spaceinvader.c datatypes.h

.PHONY: clean
clean:
	-rm invaders $(objects)
