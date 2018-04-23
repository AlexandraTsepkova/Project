name.e: 1.o
	gcc 1.o -o 1.e
name.o:	1.c
	gcc -c 1.c
cls:
	rm 1.o 1.e