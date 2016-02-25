DEST    = ../lib/libeulertools.a
CC      = g++
CFLAGS  = -Wall -g --std=c++11 -O3
FILES   = *.cc

all: lib test
	cp -av *.h ../include/	

test: test.o
	${CC} -o test ${CFLAGS} ${FILES}

lib: *.o 
	ar rvs ${DEST} *.o

*.o: ${FILES}
	${CC} ${CFLAGS} -c ${FILES}

clean:
	rm *.o 
