##
## Makefile
##
## Licensed under MIT License
## Author: Hyd3L
##

CC := gcc
CFLAGS := -Wall
LFLAGS := -lncurses
TARGET := cursesmind
PREFIX := /usr


all: compile

compile:
	$(CC) $(CFLAGS) $(LFLAGS) -o $(TARGET) *.c

install:
	mv $(TARGET) $(PREFIX)/bin

uninstall:
	rm $(PREFIX)/bin/$(TARGET)

