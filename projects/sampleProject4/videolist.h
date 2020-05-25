#ifndef VIDEOLIST_H
#define VIDEOLIST_H
//class object for a list of videos
#include "video.h"

//constants
const int CAP = 3;
const int GROWTH = 2;

//define class VideoList for array of videos and size

class VideoList
{
	private:
		Video *list;
		int size;
		int capacity;
		//growlist is a private function
		void growList();
	public:
		//constructors
		VideoList();
		VideoList(char []);
		//destructor
		~VideoList();
		//database functions
		void addVideo(Video);
		void searchByTitle();
		void showList();
		void removeVideo();
		void writeData(char []);
};

#endif
