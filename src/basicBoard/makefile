
base = Board Unit

srcs = $(addsuffix .cpp, $(base))
hdrs = $(addsuffix .h, $(base))
objs = $(addsuffix .o, $(base))

.PHONY: build

build: $(addprefix $(objLoc), $(objs))

$(objLoc)%.o: %.cpp %.h
	${CC} ${CFLAGS} -c $< -I. -o "$@"

test: ${MAKE} -C .. test

clear:
	${MAKE} 

re%:
	${MAKE} $(addprefix --assume-new=, $(srcs) $(hdrs)) "$*"
