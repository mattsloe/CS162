

#include "song.h"



/*CONSTRUCTORS*/
Song::Song()
{
    //uninitialized Song object
    strcpy(title, "No Title");
    strcpy(artist, "No Artist");
    lengthMin = 0;
    lengthSec = 0;
    strcpy(album, "No Album");
}

//constructor with parameters
Song::Song(char title[], char artist[], int lengthMin, int lengthSec, char album[])
{
    strcpy(this->title, title);
    strcpy(this->artist, artist);
    this->lengthMin = lengthMin;
    this->lengthSec = lengthSec;
    strcpy(this->album, album);
}

//copy constructor
Song::Song(const Song &aSong)
{
    strcpy(this->title, aSong.title);
    strcpy(this->artist, aSong.artist);
    this->lengthMin = aSong.lengthMin;
    this->lengthSec = aSong.lengthSec;
    strcpy(this->album, aSong.album);
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
    strcpy(title,newTitle);
}

void Song::setArtist(char newArtist[])
{
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