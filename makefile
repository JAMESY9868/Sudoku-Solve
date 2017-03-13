#!/usr/bin/make

CC = g++

CFLAGS = 

srcs = sudoku.cpp
objs = sudoku.o

sudoku: $(objs)
	${CC} -o $@.out $?

%.o: %.cpp
	${CC} $(CFLAGS) -c $<

clear:
	${RM} *.o

cleanup:
	${MAKE} clear
	${RM} *.out
