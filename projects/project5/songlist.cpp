//implementation for SongList class
#include "songlist.h"
#include "tools.h"

//SongList implementation functions

/*CONSTRUCTORS*/

SongList::SongList()
{
    //allocate memory for the array of songs
    size = 0; 
    head = NULL;
    tail = NULL;
}

SongList::SongList(const char fileName[])
{
    size = 0;head=NULL;tail=NULL;//set size to zero first
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
    Node * current, * next;
    current = head;

    while(current != NULL){
        next = current->next;
        delete current;
        current = next;
    }
    head = NULL; //??is this necessary or does it lose scope??

}

/*ACCESSOR*/

const void SongList::displayList()
{
    int num = 0;
    for (int i = 0; i < size; i++){
        cout << ++num << ". ";
        getNode(i)->data.printSong();
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
        getNode(i)->data.getArtist(tempArtist);
        toUpper(tempArtist);
        if (strstr(tempArtist, srchArtist)){
            getNode(i)->data.printSong();
        }
    }
    cout << endl;
}

/*MUTATOR*/

bool SongList::addSong(Song & newSong)
{
    Node * p;
    /*CASE 1: Empty List*/
    if(head == NULL){
        head = new Node(newSong, head); //create a new node with newSong and point head to the node
        tail = head;
        size++;
        return true;
    }else{
        p = head;
    /*CASE 2: Non-empty List*/
        //Find insertion point
        while(p != NULL){
            if(p->data <= newSong){
                if(p->next !=NULL){
                    if(newSong < p->next->data){
                        //insert node after p
                        p->next = new Node(newSong,p->next);
                        size++;
                        return true;
                        //return true
                    }
                }else{
                    //insert node at tail
                    p->next = new Node(newSong, p->next);
                    size++;
                    tail = p->next;
                    return true;
                }
            }else{
                if(newSong < p->data){
                    //insert node at head
                    head = new Node(newSong, head);
                    size++;
                    return true;
                }
            }
            p = p->next; //iterate to next node
        }
    }
    cout << "Failed to add song to LinkedList" << endl;
    return false;

    
}

void SongList::delSong()
{
    int selection = 0;
    displayList();
    cout << "Which song would you like to delete?: ";
    cin >> selection;

    if(selection <= size){
        if(!delSong(selection-1)){ //if there was an error deleting the song
            cout << "Error with delSong(index)" << endl;
        }
    }
    displayList();

}

bool SongList::delSong(int index)
{
    if(index < 0 || index >= size) return false; //check index bounds
    Node * p = head;
    //check for empty list
    if(head == NULL) return false;
    //check for list size 1
    if(size == 1){
        delete p;
        head = NULL; tail = NULL;
        size--;
        return true;
    }
    for(int i = 0; i < index-1; i++) p = p->next; //iterate to node before index
    delete p->next;
    if(index == size-1) tail = p;
    size--;
    return true;

}
//returns a pointer to a node at the index
SongList::Node * SongList::getNode(int index)
{
    //check index bounds
    if(index < 0 || index >= size) return NULL;
    Node * p = head;
    for(int i = 0; i<index; i++) p = p->next; //iterate through the List
    return p;
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
        getNode(i)->data.printFile(outFile);
    }
    outFile.close();
}

