//  Name: Song Library
//  Author: Matthew Loera
//  Date: 04/20/20
//  Program Desciption: Project 2
//  Sources: Course Notes, Lecture Video
//  
// 
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
void loadData(SongType list[], int& size, const char infile[]); //loads the songs from infile
void searchByArtist(SongType songs[], int& size); //searches for matching songs in the database and prints matches to screen
void readInSong(SongType song); //prompts user for data to fill SongType
void appendSong(SongType songs[], int& size, SongType& newSong); //adds a new SongType to the end of the array of SongType
void saveSongs(const SongType songs[], const int& size,const char outfile[]); //saves database to outfile
void removeSong(SongType songs[], int& size, int songIndex); //remove song at given index
void displaySongs(const SongType songs[],int size, int songIndex); //displays song at given index
void displaySongs(const SongType songs[],int size); //displays all songs in database

//utility functions
int getInt();
int getInt(int min, int max); //getInt with bounds checking


/*MAIN*/
int main() {
    //declare variables
    char input;
    SongType library[ARRAY_MAX_SIZE];
    int size = 0;
    //initialize data
    loadData(library, size, SONG_FILE);
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

    //save and exit
    saveSongs(library,size,SONG_FILE);
    return 0;
}


/*FUNCTION DEFINITION*/
char getInput() 
{
	cout << "Please enter your selection: ";
	char userInput = getchar();
    cin.clear();
    cin.ignore(1000,'\n');
	return tolower(userInput);
}

void executeCommand(char command, SongType songs[], int& size)
{
    SongType aSong;
    switch (command)
    {
	    case 'a': //add a song
            cout << "ADD A SONG" << endl << endl;
            readInSong(aSong);
            appendSong(songs,size,aSong);
	        break;
	    case 'b': //display all songs
            cout << "DISPLAY SONGS\n";
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


void loadData(SongType list[], int& size, const char infile[])
{
    ifstream in;
    char inputLine[STR_MAX_SIZE];
    SongType currentSong;

    char inString[STR_MAX_SIZE];

    in.open(infile);
    if(!in){
        cerr << "Failed to open " << infile << " for reading!" << endl;
        exit(1);
    }
    do{
        in.getline(inString,STR_MAX_SIZE-1,';'); //get song name
        strcpy(currentSong.songName,inString);
           // in.get(); //throw away the delimiter
        in.getline(inString, STR_MAX_SIZE-1,';'); //get artist name
        strcpy(currentSong.artist , inString);
          //  in.get();
        in >> currentSong.lengthMin; //get song length
            in.get();
        in >> currentSong.lengthSec;
            in.get();
        in.getline(inString, STR_MAX_SIZE-1,'\n'); //get album name
        strcpy(currentSong.album , inString);
           // in.ignore(STR_MAX_SIZE, '\n'); //throw away newline

        appendSong(list,size,currentSong);
    }while(!in.eof());

    in.close();
    cout << "Data imported successfully from " << infile << ". Song count: " << size << endl;
}

void searchByArtist(SongType songs[], int& size)
{
    return;
}

void readInSong(SongType song)
{
    return;
}

void appendSong(SongType songs[], int& size, SongType& newSong)
{
    songs[size] = newSong;
    size++;
    return;
}
void saveSongs(const SongType songs[], const int& size,const char outfile[])
{
    return;
}

void removeSong(SongType songs[], int& size, int songIndex)
{
    return;
}

void displaySongs(const SongType songs[], int size, int songIndex)
{
        cout << "Song " << songIndex << ": " << songs[songIndex].songName << " by " << songs[songIndex].artist <<  " | " << songs[songIndex].album << endl;
        cout <<  "     (" << songs[songIndex].lengthMin << ":" << setfill('0') << setw(2) << songs[songIndex].lengthSec << ")" << endl; //BUG: why can't I put the song length without messing up the formatting
}

void displaySongs(const SongType songs[],int size) //overload previous displaySongs() function to display all songs
{
        for(int i = 0; i < size; i++){
            displaySongs(songs, size, i);
    }
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
