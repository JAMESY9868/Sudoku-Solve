
export
RM = -@rm -fv
CC = @g++
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

# for now, will add a separate obj dir later
# The name is misleading, but it is actually used by its children `make`'s, so it needs to descend one level in file system
# might need some cleaning up
objLoc = ../../obj/
binLoc = ../../bin/

# the directory names
subTasks = basicBoard boardInterpret boardSolve general test
tasks = build test rebuild

toTest = 

# default to build everything

.PHONY: build

# The following three tasks are supposed to build/test/rebuild all the files
build: $(addprefix build-, $(subTasks))
rebuild: $(addprefix rebuild-, $(subTasks))
test: $(addprefix test-, $(toTest))

build-%:
	${MAKE} -C $* build

rebuild-%:
	${MAKE} -C $* rebuild

test-%:
	${MAKE} -C test test-$*

clear:
	${RM} ../obj/*.o
	${RM} */*.o
