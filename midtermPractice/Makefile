CC =  g++
CPPFLAGS = -Wall -g -std=c++11

all: app

app: main.o array.o 
	$(CC) $(CPPFLAGS) main.o array.o supplied.o

main.o:
	$(CC) -c main.cpp supplied.o

array.o:
	$(CC) -c array.h array.cpp supplied.o

clean:
	rm *.o
	rm app

