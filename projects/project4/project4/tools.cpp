//This is the implementation file for tools.h
#include "tools.h"

//Function implementations


//displays the menu
void displayMenu()
{
        cout << endl << "SONG DATABASE" << endl
        << "    a. Add a song" << endl
        << "    b. Display all songs" << endl
        << "    c. Remove a song by index" << endl
        << "    d. Search for a song by artist" << endl
        << "    e. Quit" << endl << endl;
}

//read the option from the user
char readOption()
{
	char input;
	cin >> input;
	cin.ignore(100, '\n');
	return input;
}

//execute the option
void exeCmd(char option, SongList &store)
{
	Song aSong;
	switch (tolower(option))
	{
	case 'a':
		addSong(aSong);
		if (store.addSong(aSong)){
			cout << "Song added!" << endl;
		}else{
			cout << "Duplicate title! Song not added!" << endl;
		}

		break;
	case 'b':
		store.displayList();
		break;
	case 'c':
		store.delSong();
		break;
	case 'd':
		store.findSong();
		break;
	case 'e':
		store.writeFile(SONG_OUT_FILE);
		break;
	default:
		cout << "Invalid input, please try again!!" << endl;
	}
}

//Name: readInt (reads and validates an integer)
int readInt()
{
	int temp = 0;
	cin >> temp;
	//data validation
	while (!cin){
	
		cin.clear();
		cin.ignore(100, '\n');
		cout << "Invalid input!! Please try again!!";
		cin >> temp;
	}
	cin.ignore(100, '\n');

	return temp;
}

//standalone overloaded addSong function
//populate aSong from the user
void addSong(Song &aSong)
{
    char inputString[STR_MAX_SIZE];
    int inputInt;

    cout << "Please enter a song name" << endl;
    cin.get(inputString,STR_MAX_SIZE,'\n');
    cin.ignore(100,'\n');
    aSong.setTitle(inputString);
    
    cout << "Please enter an artist" << endl;
    cin.get(inputString,STR_MAX_SIZE,'\n');
    cin.ignore(100,'\n');
    aSong.setArtist(inputString);
    
    cout << "Please enter an album" << endl;
    cin.get(inputString,STR_MAX_SIZE,'\n');
    cin.ignore(100,'\n');
    aSong.setAlbum(inputString);
    
    cout << "Please enter the minutes duration" << endl;
    aSong.setLengthMin(readInt());

    cout << "Please enter the seconds duration" << endl;
    aSong.setLengthSec(readInt());

    cin.clear();
    cin.ignore(1000,'\n');
}

//converts all text to upper case
void toUpper(char tempStr[]){
	for (int i = 0; i < strlen(tempStr); i++){
		tempStr[i] = toupper(tempStr[i]);
	}
}
