//implementation for SongList class
#include "songlist.h"
#include "tools.h"

//SongList implementation functions

/*CONSTRUCTORS*/

SongList::SongList()
{
    capacity = CAP;
    //allocate memory for the array of songs
    list = new Song[capacity];
    size = 0; 
}

SongList::SongList(const char fileName[])
{
    capacity = CAP;
    list = new Song[capacity];
    size = 0; //set size to zero first
    ifstream in;
    char inputLine[STR_MAX_SIZE];
    Song currentSong;

    char inString[STR_MAX_SIZE];
    int value; //to temporarily store int value from input

    in.open(fileName);
    if(!in){
        cerr << "Failed to open " << fileName << " for reading!" << endl;
        exit(1);
    }
    
    in.getline(inString,STR_MAX_SIZE-1,';'); //get song name
    while(!in.eof()){
        currentSong.setTitle(inString);
        
        in.getline(inString, STR_MAX_SIZE-1,';'); //get artist name
        currentSong.setArtist(inString);
        
        in >> value; //get song length
        currentSong.setLengthMin(value);
            in.get();
        in >> value;
        currentSong.setLengthSec(value);
            in.get();
        in.getline(inString, STR_MAX_SIZE-1,'\n'); //get album name
        currentSong.setAlbum(inString);

        if (!addSong(currentSong))
            cout << "Error adding Song!"; //add song to the list
        in.getline(inString,STR_MAX_SIZE-1,';'); //get song name
    }

    in.close();
    cout << "Data imported successfully from " << fileName << ". Song count: " << size << endl; 
}
/*DESTRUCTOR*/

SongList::~SongList()
{
    //delete list
    if(list){
        delete [] list;
        list = NULL;
    }

}

/*ACCESSOR*/

const void SongList::displayList()
{
    int num = 0;
    for (int i = 0; i < size; i++){
        cout << ++num << ". ";
        list[i].printSong();
        cout << endl;
    }
}

const void SongList::findSong()
{
    char srchArtist[STR_MAX_SIZE], tempArtist[STR_MAX_SIZE];
    cout << "Enter the artist you are looking for: ";
    cin.get(srchArtist, STR_MAX_SIZE, '\n');
    toUpper(srchArtist);
    for (int i = 0; i < size; i++){
        list[i].getArtist(tempArtist);
        toUpper(tempArtist);
        if (strstr(tempArtist, srchArtist)){
            list[i].printSong();
        }
    }
    cout << endl;
}

/*MUTATOR*/

bool SongList::addSong(Song newSong)
{
    //if size == cap, then grow the array
    if(size == capacity){
        growList();
    }
    list[size] = newSong; //deep copy
    size++;
    return true;
    
}

void SongList::delSong()
{
    int selection = 0;
    displayList();
    cout << "Which song would you like to delete?: ";
    cin >> selection;

    if(selection < size){
        for (int i = selection-1; i < size; i++){
            list[i] = list[i+1];
        }
    }
    size--;
    displayList();

}

void SongList::writeFile(const char dataFile[])
{
    ofstream outFile;
    outFile.open(dataFile);
    if(!outFile){
        cout << "File not found! Program terminating!!" << endl;
        exit(0);
    }
    for (int i = 0; i < size; i++){
        list[i].printFile(outFile);
    }
    outFile.close();
}

//adds capacity to the list when full
void SongList::growList()
{
    capacity += GROWTH;
    char tempTitle[STR_MAX_SIZE];

    Song *tempList = new Song[capacity];
    for (int i=0; i < size; i++){
        tempList[i] = list[i]; 
    }

    delete[] list;
    list = tempList;
    tempList = NULL;
}