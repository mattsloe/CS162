#ifndef SONG_H
#define SONG_H

#include <iostream>
#include <fstream>
#include <cstring>
#include <cstdlib>
#include <iomanip>

using namespace std;
/*CONSTANTS*/
const int STR_MAX_SIZE = 128;

/*Class: Song*/
class Song
{
    private:
        int lengthMin;
        int lengthSec;
        char title[STR_MAX_SIZE];
        char artist[STR_MAX_SIZE];
        char album[STR_MAX_SIZE];

    public:
        /*CONSTRUCTORS*/
        Song();
        Song(char title[], char artist[], int lengthMin, int lengthSec, char album[]); //initializer
        Song(const Song &); //copy constructor

        /*ACCESSORS*/
        const void getTitle(char returnTitle[]);
        const void getArtist(char returnArtist[]);
        const int getLengthMin();
        const int getLengthSec();
        const void getAlbum(char returnAlbum[]);

        /*MUTATORS*/
        void setTitle(char newTitle[]);
        void setArtist(char newArtist[]);
        void setLengthMin(int newLengthMin);
        void setLengthSec(int newLengthSec);
        void setAlbum(char newAlbum[]);

       /*PRINT FUNCTION*/ 
       const void printSong();
       const void printFile(ofstream & outFile);
};

#endif