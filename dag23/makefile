CFLAGS = -ansi -Wall 

dag23.out: funktion1.o funktion2.o funktion1.h funktion2.h dag23.c
	gcc dag23.c funktion1.o funktion2.o $(CFLAGS)\
	-o dag23.out

funktion1.o: funktion1.c
	gcc -c funktion1.c\
		-o funktion1.o

funktion2.o: funktion2.c 
	gcc -c funktion2.c\
		-o funktion2.o