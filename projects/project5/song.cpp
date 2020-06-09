

#include "song.h"



/*CONSTRUCTORS*/
Song::Song()
{
    //uninitialized Song object
    title = new char[8];
    artist = new char[9];
    album = new char[8];

    strcpy(title, "No Title");
    strcpy(artist, "No Artist");
    lengthMin = 0;
    lengthSec = 0;
    strcpy(album, "No Album");
}

//constructor with parameters
Song::Song(char title[], char artist[], int lengthMin, int lengthSec, char album[])
{


    this->title = new char[strlen(title)+1];
    strcpy(this->title, title);
    this->artist = new char[strlen(artist)+1];
    strcpy(this->artist, artist);

    this->lengthMin = lengthMin;
    this->lengthSec = lengthSec;

    this->album = new char[strlen(album)+1];
    strcpy(this->album, album);
}

//copy constructor
Song::Song(const Song &aSong)
{

    title = new char[strlen(aSong.title)+1];
    artist = new char[strlen(aSong.artist)+1];
    album = new char[strlen(aSong.artist)+1];

    *this = aSong;
}

//destructor
Song::~Song()
{
    //dellocate dynamic strings
    if(title){
        delete [] title;
        title = NULL;
    }
    if(artist){
        delete [] artist;
        artist = NULL;
    }
    if(album){
        delete [] album;
        album = NULL;
    }
}

/*ACCESSORS*/

const void Song::getTitle(char returnTitle[])
{
    strcpy(returnTitle, title);
}

const void Song::getArtist(char returnArtist[])
{
    strcpy(returnArtist, artist);
}

const int Song::getLengthMin()
{
    return lengthMin;
}

const int Song::getLengthSec()
{
    return lengthSec;
}

const void Song::getAlbum(char returnAlbum[])
{
    strcpy(returnAlbum, album);
}

/*MUTATORS*/

void Song::setTitle(char newTitle[])
{
    if(title){
        delete [] title;
        title = NULL;
    }
    title = new char[strlen(newTitle)+1];
    strcpy(title,newTitle);
    
}

void Song::setArtist(char newArtist[])
{
    if(artist){
        delete [] artist;
        artist = NULL;
    }
    artist = new char[strlen(newArtist)+1];
    strcpy(artist,newArtist);
}


void Song::setLengthMin(int newLengthMin)
{
    lengthMin = newLengthMin;
}

void Song::setLengthSec(int newLengthSec)
{
    lengthSec = newLengthSec;
}

void Song::setAlbum(char newAlbum[])
{
    if(album){
        delete [] album;
        album = NULL;
    }
    album = new char[strlen(newAlbum)+1];
    strcpy(album,newAlbum);
}

/*PRINT FUNCTION*/
const void Song::printSong()
{
    cout << title << ';' << artist << ';' << lengthMin << ':'
        << setfill('0') << setw(2) << lengthSec << ';' << album;
}

const void Song::printFile(ofstream & outFile)
{
    outFile << title << ';'
        << artist << ';'
        << lengthMin << ';'
        << lengthSec << ';'
        << album << '\n';
}

//assignment operator overload
const Song& Song::operator= (const Song& aSong)
{
    //if it is a self copy, do nothing
    if (this == &aSong)
        return *this;
    
    //make current object a copy of the passed in student
    else{
    //set song name
        if(this->title){
            delete [] this->title;
            title = NULL;
        }
        title = new char[strlen(aSong.title)+1];
        strcpy(this->title,aSong.title); 
    //set artist
        if(this->artist){
            delete [] this->artist;
            artist = NULL;
        }
        artist = new char[strlen(aSong.artist)+1];
        strcpy(this->artist,aSong.artist);
    //set length
        this->lengthMin = aSong.lengthMin;
        this->lengthSec = aSong.lengthSec;
    //set album
        if(this->album){
            delete [] this->album;
            album = NULL;
        }
        album = new char[strlen(aSong.album)+1];
        strcpy(this->album,aSong.album);
    }

    return *this;
}

//operator overload for <
const bool Song::operator < (const Song& aSong)
{
    if(strcmp(this->title, aSong.title) < 0){
        return true;
    }
    return false;
}

//operator overload for <=
const bool Song::operator <= (const Song& aSong)
{
    if(strcmp(this->title,aSong.title) <= 0){
        return true;
    }
    return false;
}