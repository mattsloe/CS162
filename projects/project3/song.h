#ifndef SONG_H
#define SONG_H

/*CONSTANTS*/
const int STR_MAX_SIZE = 128;

/*Class: Song*/
class Song
{
    private:
        char[] title;
        char[] artist;
        int lengthMin;
        int lengthSec;
        char[] album;

    public:
        /*CONSTRUCTORS*/
        Song();
        Song(char title[], char artist, int lengthMin, int lengthSec, char[] album); //initializer
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
}

#endif