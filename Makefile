CC = gcc
CFLAGS = -Wall
LFLAGS = -lncurses
TARGET = cursesmind

all: compile

compile:
	$(CC) $(CFLAGS) $(LFLAGS) -o $(TARGET) *.c

