all: video

video: videolist.o video.o tools.o driver.o
	g++ -g videolist.o video.o tools.o driver.o -o video

videolist.o: videolist.cpp
	g++ -c -g videolist.cpp
video.o: video.cpp
	g++ -c -g video.cpp

driver.o: driver.cpp
	g++ -c -g driver.cpp

tools.o: tools.cpp
	g++ -c -g tools.cpp

clean:
	rm *.o video	
