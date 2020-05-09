/*
Title:
Date:
Author
Sources: Project 2. Project design modeled from Sample Project 3 from Instructor Sengupta.
*/

#include "tools.h"
#include <cstring>
#include <cstdlib>

//constants
const char SONG_FILE[10] = "songs.txt"; //name of the source file
const char SONG_OUT_FILE[] = "songs.out"; //output file

int main(){
    //Create and initialize Songlist
    SongList library(SONG_FILE);
    char option;

    //display the menu
    do{
        //
    }while (tolower(option) != 'q');

    return 0;
    
}