CC=g++
CCFLAGS=-Wall -g -O3 --std=c++14
OBJ=main
SRC=main.cc
LIBS=-lprimes -leulertools
LIBDIR=-L../lib
INCDIR=-I../include

all: eulertools primes
	${CC} ${CCFLAGS} -o ${OBJ} ${SRC} ${LIBDIR} ${INCDIR} ${LIBS}

eulertools:
	cd ../eulertools; make

primes:
	cd ../primes; make
