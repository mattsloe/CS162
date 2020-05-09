#ifndef SONGLIST_H
#define SONGLIST_H

#include "song.h"
/*CONSTANTS*/
const int ARRAY_MAX_SIZE = 128;

/*Class: SongLIST*/
class SongList
{
    private:
        Song list[ARRAY_MAX_SIZE];
        int size;

    public:
        /*CONSTRUCTOR*/
        SongList();
        SongList(const char fileName[]); //creates a SongList and populates it with data from fileName

        /*DESTRUCTOR*/
        ~SongList();

        /*ACCESSOR*/
        void displayList();
        void findSong();

        /*MUTATOR*/
        void delSong();
        void writeFile();
}
#endif