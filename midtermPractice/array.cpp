//array.cpp 

#include "array.h"

//put the implementations of your assigned functions here
int numOfEven(int list[], int size)
{
    int evenCount = 0;
    for(int i=0; i<size;i++)
    {
        if(list[i]%2 == 0) evenCount++;
    }
    return evenCount;

}

int insert(int list[], int& size, int newInt, int position)
{

    //shift elements forward
    for(int i = size; i < position; i--){
        list[i+1]=list[i];
    }
   //increase array size
   size++; 
   //insert newInt at position
   list[position]=newInt;
   
   return size;
}