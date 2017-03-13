#!/usr/bin/make

CC = g++

CFLAGS = 

srcs = sudoku.cpp
objs = sudoku.o

sudoku: $(objs)
	${CC} $(CFLAGS) -o $@.out $?

%.o: %.cpp
	${CC} $(CFLAGS) -c $<

clear:
	${RM} *.o

cleanup:
	${MAKE} clear
	${RM} *.out
