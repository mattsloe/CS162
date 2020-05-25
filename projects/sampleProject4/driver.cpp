#include "video.h"
#include "tools.h"

int main()
{
	//create a list of videos.
	char fileName[MAXCHAR] = "videos.txt";
	VideoList store(fileName);
	char option;
    do
    {
        displayMenu();
        option = readOption();
        exeCmd(option, store);
    }while(tolower(option != 'q'));
    store.writeData(fileName);

	return 0;
}
