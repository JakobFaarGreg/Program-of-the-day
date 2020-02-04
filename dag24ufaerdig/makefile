CFLAGS = -ansi -Wall

dag24.out: funktion.o funktion.h dag24.c
	gcc dag24.c funktion.o $(CFLAGS)\
	-o dag24.out

funktion.o:	funktion.c
	gcc -c funktion.c\
		-o funktion.o