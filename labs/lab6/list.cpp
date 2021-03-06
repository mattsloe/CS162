//put your implementation of LinkedList class here
#include "list.h"

LinkedList::LinkedList() //default constructor
{
    //create an empty list: No nodes. prev and next are nullptr
    size = 0;
    head = nullptr;
    tail = nullptr;
}

bool LinkedList::addAtBeginning(int val) //appends an item at the beginning
{
    Node * newNodePtr = new Node(val);
    if(newNodePtr == nullptr) return false; //make sure the new node was allocated
    newNodePtr->next = head; //set next pointer to next item in list
    head = newNodePtr; //set head to point to new node
    if(size > 0){
    newNodePtr->next->prev = newNodePtr; //set next node to point to the new node
    }else{
        tail = newNodePtr; //if this is a new list, set the tail to be the new node
    }
    size++; //increment size
    return true;
}

bool LinkedList::remove(int val) //removes any node whose data matches val
{
    bool flag = false;
    //check the bounds of the argument, check if the list is populated
    Node * deletedNode, * p, * q;
    p = head;
    //iterate through the list
    while(p != nullptr){
        //check to delete node
        if(p->data == val){
            if(p->prev != nullptr){
                p = p->prev;
                deletedNode = p->next;
                p->next = deletedNode->next; //repoint the pointers
                q = p->next;
                if(q != nullptr) q->prev = p;
                delete deletedNode; //deallocate the node
                size--; //decrement the size of the list
                if(p->next == nullptr) tail = p;
                p = p->next;
            }else{
                if(p->next == nullptr){ //if a list with only one node
                    delete p;
                    head = nullptr;
                    tail = nullptr;
                    size = 0;
                    p = p->next;
                   
                }else{
                    deletedNode = p;
                    p = p->next;
                    p->prev = nullptr;
                    delete deletedNode;
                    head = p;
                    size--;
                }
            }
            flag = true;
        }else{
            p = p->next;
        }
        //set pointer to next node
    } //pointer is now pointing at node before the deleted node
    return flag;
}

void LinkedList::printForward() const //prints the list in order
{
    Node *node;
    node = head;
    cout << "Traversal in forward direction" << endl;
    while(node != nullptr){
            cout<<node->data<< ' ';
            node = node->next;
    }
    cout << endl;
}

void LinkedList::printBackward() const //prints the list in reverse order
{
    Node * node;
    node = tail;
    cout << "Traversal in reverse direction" << endl;
    while(node != nullptr){
        cout << node->data << ' ';
        node = node->prev;
    }
    cout << endl;
}