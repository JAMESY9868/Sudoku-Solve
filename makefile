




# Currently only redirects. 
.PHONY: main

main:
	${MAKE} -C src
%:
	${MAKE} -C src $*
