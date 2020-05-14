/*
Title: Song Database
Date: 05/11/2020
Author: Matt Loera
Sources: Project 2. Project design modeled from Sample Project 3 from Instructor Sengupta.
*/

#include "tools.h"
#include <cstring>
#include <cstdlib>

//constants
const char SONG_FILE[10] = "songs.txt"; //name of the source file
//const char SONG_OUT_FILE[] = "songs.out"; //output file

int main(){
    //Create and initialize Songlist
    SongList library(SONG_FILE);
    char option;

    //display the menu
    do{
        displayMenu();
        option = readOption();
        exeCmd(option, library);
    }while (tolower(option) != 'e');

    return 0;
    
}