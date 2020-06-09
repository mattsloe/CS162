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
        int size;
       // void growList();
        struct Node
        {
            Node (Song & newSong, Node * nextNode) //initialized constructor
            {
                data = newSong;
                next = nextNode;
            }
            Song data;
            Node * next;
        };
        typedef struct Node Node;
        //next time, typedef a Nodeptr `typedef struct Node * Nodeptr`
        typedef Node * Nodeptr;
        Node * head, * tail; //remember to update head and tail when appending/deleting
        bool delSong(int index); //deletes a song at a given index
        Node * getNode(int index); //returns a pointer to node at index
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

        bool addSong(Song&); //adds a song to the list
        void delSong(); //deletes a song from the list
        void writeFile(const char dataFile[]); //writes the dada back to the file
};
#endif