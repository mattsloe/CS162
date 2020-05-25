//This is the implementation file for video.h (the Video class)
#include "video.h"

//default constructor
Video::Video()
{

        //allocate memory for title
	title = new char[MAXCHAR];
	strcpy(title, "No title");
	qty = 0;
	rating =0;
}

//constructor with parameters
Video::Video(char tempTitle[],int tempQty, double tempRating)
{
        
	//allocate memory
	title = new char[strlen(tempTitle) + 1];
	strcpy(title, tempTitle);
	qty = tempQty;
	rating = tempRating;
}

//Copy Constructor
Video::Video(const Video &aVideo)
{

	title = new char[strlen(aVideo.title) + 1];
	*this = aVideo;
}


//destructor
Video::~Video()
{
	//deallocate memory for title
	if(title)
	{
		delete [] title;
		title = NULL;
	}
}

//mutator functions
void Video::setTitle(char newTitle[])
{
	//if title exists, delete and reallocate just enough for newTitle
	if(title)
	{
		delete [] title;
		title = NULL;
	}
	title = new char[strlen(newTitle)+1];
	strcpy(title, newTitle);
}


void Video::setQty(int newQty)
{
	qty = newQty;
}

void Video::setRating(double newRating)
{
	rating = newRating;
}

//accessor functions
void Video::getTitle(char returnTitle[]) const
{
	strcpy(returnTitle, title);
}

int Video::getQty() const
{
	return qty;
}

double Video::getRating() const
{
	return rating;
}

//prints to console
void Video::printVideo()
{
	cout << title << ';' << qty << ';' << rating << endl;
}

//prints to file
void Video::printVideo(ofstream &outFile)
{
	outFile << title << ';' << qty << ';' << rating << endl;
}	




//assignment operator overloaded
const Video& Video::operator= (const Video& aVideo)
{
	//if it is a self copy, don't do anything
	if (this == &aVideo)
		return *this;
	//make current object *this a copy of the passed in student
	else
	{
		strncpy(this->title, aVideo.title, strlen(aVideo.title) + 1);
		//this->setTitle(aVideo.title);
		this->qty = aVideo.qty;
		this->rating = aVideo.rating;

		return *this;
	}
}
