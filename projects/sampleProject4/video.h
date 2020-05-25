#ifndef VIDEO_H
#define VIDEO_H
//Class object for video has title, quantity, and rating
#include <iostream>
#include <cstring>
#include <fstream>
using namespace std;

//constants
const int MAXCHAR = 101;
//data type for Video
class Video
{
    private:
	char *title;
    	int qty;
    	double rating;
	public:
		//constructors
		//default constructor
		Video();
		//constructor with parameters
		Video(char [], int, double);
		//copy constructor
		Video(const Video &aVideo);
		//destructor
		~Video();
		//mutator functions
		void setTitle(char []);
		void setQty(int);
		void setRating(double);
		//accessor functions
		void getTitle(char []) const;
		int getQty() const;
		double getRating() const;
		//print video
		void printVideo();
		void printVideo(ofstream &);
		//assignment operator overloading
		const Video& operator= (const Video& aVideo);		
};

#endif

