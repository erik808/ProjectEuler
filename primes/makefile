DEST    = ../lib/libprimes.a
CC      = g++
CFLAGS  = -Wall -c --std=c++11 -O3
FILES   = *.cc

all: lib
	cp -av *.h ../include/

lib: *.o 
	ar rvs ${DEST} *.o

*.o: ${FILES}
	${CC} ${CFLAGS} ${FILES}

clean:
	rm *.o 
