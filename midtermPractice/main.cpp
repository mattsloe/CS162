#include "array.h"
using namespace std;

const int CAP = 100;
int main()
{
	int list[CAP];
	int size = 10;
    build(list, size);
    display(list, size);

    //PLEASE PUT YOUR CODE HERE to call the function assigned
    cout << "Initial list created by supplied.o\n";

    cout << "Number of evens in the list:  " << numOfEven(list,size);

    //Add an element to the list
    if(insert(list,size,2,5)){
        cout <<"insert() successful!" << endl;
    }
    cout << "List after inserting 2 at position 5" << endl;
    display(list, size);
    cout << "Number of evens in the list: " << numOfEven(list,size); 
    
    return 0;
}
