//This is the implementation file for tools.h
#include "tools.h"
#include "video.h"
//Function implementations


//displays the menu
void displayMenu()
{
	cout << "Welcome to the VideoStore:" << endl << endl;
	cout << "Pick an option" << endl;
	cout << "[A-a]: Add a movie" << endl;
	cout << "[D-d]: Display the List" << endl;
	cout << "[T-t]: Find a movie by title" << endl;
	cout << "[R-r]: Remove a movie" << endl;
	cout << "[Q-q]: Quit" << endl;
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
void exeCmd(char option, VideoList &store)
{
	Video aVideo;
	switch (tolower(option))
	{
	case 'a':
            addVideo(aVideo);
	    store.addVideo(aVideo);
            break;
	case 'd':
	    store.showList();
	    break;
	case 'r':
            store.showList();
            store.removeVideo();
	    break;
	case 't':
            store.searchByTitle();
	    break;
	case 'q':
	    break;
	default:
	    cout << "Invalid input, please try again!!" << endl;
	}
}

//Name: readInt (reads and validates an integer)
//input: none
//output: error message
//return: int
int readInt(const char prompt[])
{
	int temp = 0;
	cout << prompt;
	cin >> temp;
	//data validation
	while (!cin)
	{
		cin.clear();
		cin.ignore(100, '\n');
		cout << "Invalid input!! Please try again!!";
		cin >> temp;
	}
	cin.ignore(100, '\n');

	return temp;
}

//standalone overloaded addVideo function
//populate aVideo from the user
void addVideo(Video &aVideo)
{
	char tempTitle[MAXCHAR];
	int tempQty = 0;
	double tempRating;
    cout << "Enter a movie name:";
    cin.get(tempTitle, MAXCHAR, '\n');
    convertCase(tempTitle);
    cin.ignore(100, '\n');
    tempQty = readInt("Enter quantity:");
    cout << "Please enter the rating of the movie:";
    cin >> tempRating;
	//populate aVideo calling the mutator functions
	aVideo.setTitle(tempTitle);
	aVideo.setQty(tempQty);
	aVideo.setRating(tempRating);
}

//converts all text to upper case
void convertCase(char tempStr[])
{
	//for(int i = 0; tempStr[i] != '\0'; i++)

	for (int i = 0; i < strlen(tempStr); i++)
	{
		tempStr[i] = toupper(tempStr[i]);
	}
}
