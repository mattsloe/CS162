#ifndef LIST_H
#define LIST_H

#include <iostream>
using namespace std;

class LinkedList
{
private:
	struct Node
	{
		Node (const int value) //default constructor for Node
		{
			data = value;
			prev = nullptr;
			next = nullptr;
		}
		int data;
		Node * next;
		Node * prev;
	};
	Node * head, * tail; //remember to update the head when appending a node to the list
public:
	LinkedList();
	bool addAtBeginning(int val);
	bool remove(int val);
	void printForward() const;
	void printBackward() const;
};


#endif
