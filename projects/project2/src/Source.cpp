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
const char SONG_OUT_FILE[] = "songs.out"; //output file

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
void readInSong(SongType& song); //prompts user for data to fill SongType
void appendSong(SongType songs[], int& size, SongType& newSong); //adds a new SongType to the end of the array of SongType
bool saveSongs(const SongType songs[], const int& size,const char outfile[]); //saves database to outfile, returns true if completed successfully
void removeSong(SongType songs[], int& size, int songIndex); //remove song at given index
void displaySongs(const SongType songs[],int size, int songIndex); //displays song at given index
void displaySongs(const SongType songs[],int size); //displays all songs in database



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
    int index;

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
            cin >> index;
            cin.ignore(1000,'\n');
            removeSong(songs, size, index);
	        break;
	    case 'd': //search for a song by artist
            searchByArtist(songs, size);
	        break;
	    case 'e': //quit
            cout << "SAVING..." << endl;
            aSong = songs[5];
            if(!saveSongs(songs,size,SONG_OUT_FILE)) cout << "error saving file\n"; //save to outfile
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
    //get search term from user
    char searchTerm[ARRAY_MAX_SIZE];
    cout << "What is the name of the artist you want to find? ";
    cin.getline(searchTerm,ARRAY_MAX_SIZE);
    cout << "Results:\n\n";
    int results = 0;
    //return matches
    for( int i = 0; i < size; i++){
        if(strcmp(songs[i].artist,searchTerm) == 0){
            displaySongs(songs, size, i);
            results++;
        }
    }
    if (results == 0) cout << "No Matches Found\n";

    cout << "\nPress ENTER when done.";
    cin.get(); //BUG: requires user to pres ENTER twice
    cin.clear();
    cin.ignore(1000,'\n');
}

void readInSong(SongType& song)
/*  TODO:
    -clean user input of ';' delimiter
    -validate user input
*/
{
    char inputString[STR_MAX_SIZE];
    int inputInt;

    cout << "Please enter song name" << endl;
    cin.getline(inputString, STR_MAX_SIZE, '\n');
    strcpy(song.songName,inputString);

    cout << "Please enter the artist" << endl;
    cin.getline(inputString, STR_MAX_SIZE, '\n');
    strcpy(song.artist, inputString);

    cout << "Please enter the album" << endl;
    cin.getline(inputString, STR_MAX_SIZE, '\n');
    strcpy(song.album, inputString);

    cout << "Please enter the minutes duration" << endl;
    cin >> inputInt;
    song.lengthMin = inputInt;

    cout << "Please enter the seconds duration" << endl;
    cin >> inputInt;
    song.lengthSec = inputInt;

    cin.clear(); //clear the buffer
    cin.ignore(1000,'\n');
}

void appendSong(SongType songs[], int& size, SongType& newSong)
{
    songs[size] = newSong;
    size++;
    return;
}
bool saveSongs(const SongType songs[], const int& size,const char outfile[])
{
    //create output file
    ofstream out{outfile};
    //write to file
    for(int i = 0; i < size; i++){
        out << songs[i].songName << ';';
        out << songs[i].artist << ';';
        out << songs[i].lengthMin << ';';
        out << songs[i].lengthSec << ';';
        out << songs[i].album << '\n';
    }
    //close the file and create it
    out.close();
    return 1;
}

void removeSong(SongType songs[], int& size, int songIndex)
{
    if(songIndex < size){ //check bounds
        //reduce the size of the array
        size--;
        //move elements one space ahead
        for(int i = songIndex; i < size; i++){
            songs[i] = songs[i+1];
        }
    }else cout << "Index out of bounds!\n";
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
/*
int getInt()
{
    return 0;
}

int getInt(int min, int max)
{
    return 0;
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
