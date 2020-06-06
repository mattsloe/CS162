#ifndef SONGLIST_H
#define SONGLIST_H

#include "song.h"
/*CONSTANTS*/
const int ARRAY_MAX_SIZE = 128;

const int CAP = 3;
const int GROWTH = 2;

/*Class: SongLIST*/
class SongList
{
    private:
        Song *list;
        int size;
        int capacity;

        void growList();

    public:
        /*CONSTRUCTOR*/

        SongList(); //Default Constructor
        SongList(const char fileName[]); //creates a SongList and populates it with data from fileName

        /*DESTRUCTOR*/
        ~SongList();

        /*ACCESSOR*/

        const void displayList(); //prints the list
        const void findSong(); //finds a song in the list

        /*MUTATOR*/

        bool addSong(Song); //adds a song to the list
        void delSong(); //deletes a song from the list
        void writeFile(const char dataFile[]); //writes the dada back to the file
};
#endif