#!/usr/bin/make

RM = -@rm -fv
CC = g++
CFLAGS = -std=c++11

base = Sudoku Unit Board

srcs = $(addsuffix .cpp, $(base))
hdrs = $(addsuffix .h, $(base))
objs = $(addsuffix .o, $(base))

RM = -@rm -fv
CC = g++
CSTD = -std=c++11
CDEBUGINFO = -g3
CWARNING = -Wall -Wextra -Wuninitialized -Wmaybe-uninitialized -Wmissing-declarations -Wredundant-decls
CERROR = -Werror=return-type -Werror=redundant-decls -Werror=missing-declarations
LNKR_FLAG = -Wl,--no-undefined
FATAL_FLAG = -Wfatal-errors

# The following two lines indicate flags not recognized in travis machine.
CWARNING_ADDITIONAL = -Wnull-dereference -Wmisleading-indentation
CERROR_ADDITIONAL = -Werror=null-dereference
COMMAND_LINE_ADDITIONAL =

CFLAGS = $(CSTD) $(CWARNING) $(CERROR) $(CDEBUGINFO) $(LNKR_FLAG) $(COMMAND_LINE_ADDITIONAL)

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


