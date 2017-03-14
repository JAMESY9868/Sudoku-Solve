#!/usr/bin/make

CC = g++
CFLAGS = 

RM = -rm -fv

srcs = sudoku.cpp unit.cpp board.cpp
objs = sudoku.o   unit.o   board.o
hdrs = sudoku.h   unit.h   board.h

sudoku.out: $(objs)
	${CC} $(CFLAGS) -o $@ $?

%.o: %.cpp %.h
	${CC} $(CFLAGS) -c $< -I.

clear:
	${RM} *.o

cleanup:
	${MAKE} clear
	${RM} *.out

remake:
	${MAKE} cleanup sudoku.out
	
test:
	${MAKE} remake cleanup


