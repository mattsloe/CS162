//
//  main.cpp
//  Program Desciption: Add student to database, delete student from the database and print database.
//
//  Created by Shawli on 4/8/20.
//  Copyright © 2020 Shawli. All rights reserved.
//

//Include header files
#include <iostream>
#include<cstring>
#include<cctype>
#include<iomanip>
#include<fstream>
#include<stdio.h>

using namespace std;

/*CONSTANTS*/
const int ARRAY_MAX_SIZE = 128;
const int STR_MAX_SIZE = 128;
const char SONG_FILE[10] = "songs.txt"; //name of the source file

/*DATA STRUCTURES*/
struct SongType
{
    //Member Variables
    char songName[STR_MAX_SIZE];
    char artist[STR_MAX_SIZE];
    int lengthMin;
    int lengthSec;
    char album[STR_MAX_SIZE];
};

/*FUNCTION DECLARATION*/
//menu functions
char getInput();
void executeCommand(char command, SongType songs[], int& size);

//program functions
void loadData(char& infile); //loads the songs from infile
void searchByArtist(SongType songs[], int& size); //searches for matching songs in the database and prints matches to screen
void addSong(SongType songs[], int& size); //prompts user for data to fill SongType, adds it to the database
void saveSongs(const SongType songs[], const int& size, char& outfile); //saves database to outfile
void removeSong(SongType songs[], int& size, int songIndex); //remove song at given index
void displaySongs(const SongType songs[],const int& size, int songIndex); //displays song at given index
void displaySongs(const SongType songs[],const int& size); //displays all songs in database

//utility functions
int getInt();
int getInt(int min, int max); //getInt with bounds checking
/*
void addDB(SongType song[], int& count);
void deleteDB(SongType song[], int& count);
void printDB(SongType song[], const int count);
*/

/*MAIN*/
int main() {
    //declare variables
    char input;
    SongType library[ARRAY_MAX_SIZE];
    int size = 0;

	//display menu
    do {
        cout << endl << "SONG DATABASE" << endl
            << "    a. Add a song" << endl
            << "    b. Display all songs" << endl
            << "    c. Remove a song by index" << endl
            << "    d. Search for a song by artist" << endl
            << "    e. Quit" << endl << endl;
        //read in command
        input = getInput();
        //execute command
        executeCommand(input, library, size);
    } while (input != 'e');

    return 0;
}


/*FUNCTION IMPLEMENTATION*/
char getInput() 
{
	cout << "Please enter your selection: ";
	char userInput = getchar();
	return tolower(userInput);
}

void executeCommand(char command, SongType songs[], int& size)
{
    switch (command)
    {
	    case 'a': //add a song
            cout << "ADD A SONG" << endl << endl;
            addSong(songs, size);
	        break;
	    case 'b': //display all songs
            cout << "DISPLAY SONGS";
            displaySongs(songs, size);
	        break;
	    case 'c': //remove a song by index
            cout << "REMOVE A SONG" << endl
                << endl << "Enter the index of the song you want to remove: ";
            removeSong(songs, size, getInt(0, size - 1));
	        break;
	    case 'd': //search for a song by artist
            searchByArtist(songs, size);
	        break;
	    case 'e': //quit
            cout << "QUITTING..." << endl;
	        break;
	    default:
	        cout << "Illegal Command! " << endl;
	        break;
    }

}


void loadData(char& infile)
{
}

void searchByArtist(SongType& songs, int& size)
{
}

void addSong(SongType& songs, int& size)
{
}

void saveSongs(const SongType& songs, const int& size, char& outfile)
{
}

void removeSong(SongType& songs, int& size, int songIndex)
{
}

void displaySongs(const SongType songs[], const int& size, int songIndex)
{
}

void displaySongs(const SongType songs[],const int& size)
{
}

int getInt()
{
    return 0;
}

int getInt(int min, int max)
{
    return 0;
}

/*
void SongType::readDB()
{
    cout << "Please enter song name" << endl;
    cin.getline(songName, STR_MAX_SIZE, '\n');
    cout << "Please enter the artist" << endl;
    cin.getline(songName, STR_MAX_SIZE, '\n');
    cout << "Please enter student gpa" << endl;
    cin >> gpa;
}

void SongType::listDB()
{
    cout << fixed << setprecision(2);
    cout << left << setw(15) << songName << setw(7) << id << setw(5) << gpa << endl;

}

void addDB(SongType student[], int& count)
{

    char response[4] = "yes";
    while ((strcmp(response, "no") != 0))
    {
        student[count].readDB();
        count++;
        cout << "Do you want to continue? Enter yes or no." << endl;
        cin.ignore(5, '\n');
        cin.getline(response, 4);
    }

}

void deleteDB(SongType student[], int& count)
{
    int delnum;
    cout << "Enter the index number you want to delete" << endl;
    cin >> delnum;
    for (int i = delnum; i < count; i++)
    {
        student[i - 1] = student[i];
    }
    count--;
}

void printDB(SongType student[], const int count)
{
    cout << left << setw(6) << "Index" << setw(15) << "Student" << setw(7) << "ID" << setw(5) << "GPA" << endl;
    int index = 1;
    for (int i = 0; i < count; i++)
    {
        cout << left << setw(6) << index;
        student[i].listDB();
        index++;
    }
}
*/