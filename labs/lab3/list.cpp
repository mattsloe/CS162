#include "list.h"
#include <iostream>
using namespace std;

bool insert(int position, int val, int intList[], int& size)
{
	//inserts the value
	if (position < 100) {
		if (position >= size) size = position+1; //change the array size if the position is greater than the array size
		intList[position] = val; //put val into the intList at the right index
		return true;
	}
	else return false;
}

bool remove(int position, int& val, int intList[], int& size)
{
	//insert your code here and modify the following line
	//make sure position is valid
	if (position < size) {

		//store value to be deleted to val
		val = intList[position];
		//move the other values up by one
		for(int i = position; i < size-1; i++)
		{
			intList[position] = intList[position + 1];
		}
		//decrement size
		size--;
		return true;
	}
	else return false;
}

void print(const int intList[], int size)
{
	cout << endl << "[ ";
	for(int i=0; i<size; i++)
	{
		cout << intList[i] << " ";
	}
	cout << "]" << endl;
}



