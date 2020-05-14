#ifndef TOOLS_H
#define TOOLS_H

#include "songlist.h"
const char SONG_OUT_FILE[] = "songs.out";
/*FUNCTION PROTOTYPES*/

//reads in an int from the user
int getInt();

//Prints the menu to command line for the user
void displayMenu();

//reads the user's selection from the menu
char readOption();

//Executes the user selected option
void exeCmd(char option, SongList & library);

//populates aSong from user input
void addSong(Song & aSong);

//converts all text to uppercase char-wise
void toUpper(char inString[]);
#endif