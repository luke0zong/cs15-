# This is a simple example of a Makefile.

CC = c99
CFLAGS = -Wall -Wextra -pedantic


prog: tester.o mod.o
	$(CC) $(CFLAGS) -o prog tester.o mod.o

tester.o: tester.c mod.h
	$(CC) $(CFLAGS) -c tester.c

mod.o: mod.c mod.h
	$(CC) $(CFLAGS) -c mod.c

clean:
	rm -f *.o prog a.out