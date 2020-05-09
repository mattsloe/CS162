#ifndef ARRAY_H
#define ARRAY_H

//array.h
#include <iostream>
#include <cstring>
#include <cctype>
using namespace std;

/* These functions are already written and can be called to test out your code */
void build(int list[], int size);  //supplied
void display(int list[], int size);  //supplied

/* *****************YOUR TURN! ******************************** */
//Write your function prototype here:
int numOfEven(int list[], int size);
//computes and returns the number of even integers in the list

int insert(int list[], int&size, int newInt, int position);
//inserts newInt into the list at index "position" and updates the size of the list

#endif
