CC=gcc
CFLAGS=-I. -ggdb3 -Wall -Wextra -std=c11 -lncurses 
objects= invaders.o cursesrenderer.o cursesinputhandler.o


invaders: $(objects) 
	$(CC) -o invaders $(objects) 

invaders.o: renderer.h inputhandler.h
cursesrenderer.o: cursesrenderer.c
cursesinputhandler.o: cursesinputhandler.c

.PHONY: clean
clean:
	-rm invaders $(objects)
