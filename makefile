#!/usr/bin/make

CC = g++

CFLAGS = 

srcs = sudoku.cpp unit.cpp
objs = sudoku.o unit.o
hdrs = sudoku.h unit.h

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
