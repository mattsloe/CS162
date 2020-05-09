all: app

#this line won't work. Linking error ??????????
app: main.o tools.o songlist.o song.o
	gcc -g -Wall -o app main.o tools.o songlist.o song.o
main.o: tools.o
	gcc -c -Wall main.cpp
tools.o:
	gcc -c -Wall tools.cpp
songlist.o: tools.o song.o
	gcc -c -Wall songlist.cpp
song.o:
	gcc -c -Wall song.cpp
clean:
	rm *.o
	rm app
