/*
	Program: Assignment 1
	Author: Matthew Loera
	Date: 4/5/20
	Description: This program adds Products into the Shopping Cart and prints out a running total each time.
	When the user checks out, this program prints the total.
	Sources: Program Assignment sheet and example code for text validation from Module 1
*/

#include <iomanip>
#include <iostream>
using namespace std;

/*CONSTANTS*/
const int MAX_LENGTH = 30; //maximum length of the cstrings
const double TAX_RATE = 0; //tax rate

/*DATA STRUCTURES*/

/*FUNCTIONS*/
void getTextInput(char* inString, int strLen); //takes a reference to a cstring and populates the string with valid input

double getNumInput(); //returns a valid double from user input

double getNumInput(double min, double max); //gets input from user using getNumInput(), with bounds checking

int main()
{
	double runningTotal = 0; //holds the running total for items in cart
	char prodName[MAX_LENGTH]; //holds the current product name
	double prodPrice; //holds the current product price
	cout.setf(ios::fixed, ios::floatfield); cout.setf(ios::showpoint); cout.precision(2); //set output formatting for numbers
	
	bool readyToCheckOut = false;
	do {
	/*Prompt fo product to add to cart*/
		cout << "Please enter a product name: ";
		getTextInput(prodName, MAX_LENGTH); //use getTextInput to retrieve product name

		cout << "Please enter the price: ";
		prodPrice = getNumInput(0, 9999); //use getNumInput to retrieve a valid price from the user

	/*Echo the product back to the user to confirm input*/
		cout << left << setw(20) << prodName << " | ";
		cout << setw(10) << "$" << prodPrice << endl;
		
		cout << "1) CONFIRM\n" << "2) CANCEL\n";
		if(getNumInput(1, 2) == 1) runningTotal += prodPrice; //add the prodPrice to the running total if the user confirms

	/*Prompt for checkout*/
		cout << "Press 1 to add more items or 2 to check out." << endl; 
		if (getNumInput() == 2) readyToCheckOut = true;
		
	} while (!readyToCheckOut);
	/*Checkout*/
	cout << "SUBTOTAL:  " << runningTotal << endl;
	cout << "GRAND TOTAL @ " << TAX_RATE * 100 << "% tax:  " << TAX_RATE * runningTotal << endl;
	
}

void getTextInput(char* inString, int strLen)
{
	cin.get(inString, strLen);
	while (!cin) //check if the input failed during data retrieval
	{
		cin.clear(); //resets the failbit
		cin.get(inString, strLen);
		cin.ignore(1000, '\n');
	}

}

double getNumInput()
{
	double output = -999.99;
	cin >> output;	//get input from user
	while (!cin)
	{
		cin.clear();
		cin.ignore(1000, '\n');	//clear cin buffer

		cout << "You entered illegal input. Please try again: ";
		cin >> output;
	}
	cin.ignore(1000, '\n');	//clear cin buffer
	return output;
}

double getNumInput(double min, double max)
{
	double output = getNumInput();
	while (output < min || output > max)		//check that output is within bounds
	{
		cout << "The number must be between " << min << " and " << max << endl;
		cout << "Please try again: ";
		output = getNumInput();
	}
	return output;
}