CFLAGS = -g -o1 -Wall
cc = gcc

arrayList: main.o arrayList.o

main.o: main.c main.h

arrayList.o: arrayList.c arrayList.h

clean:
	rm -f* .o
