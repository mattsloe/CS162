/*
	Program: Assignment 1
	Author: Matthew Loera
	Date: 4/5/20
	Description: This program adds Products into the Shopping Cart and prints out a running total each time.
	When the user checks out, this program prints an itemized receipt as well as the total.
	Sources: Program Assignment sheet and example code for text validation from Module 1
*/

#include <iomanip>
#include <iostream>
using namespace std;

/*CONSTANTS*/
const int MAX_LENGTH = 30; //maximum length of the cstrings
const double TAX_RATE = 0; //tax rate

/*DATA STRUCTURES*/
struct Product
{
	double cost;
	string productName;
};

/*FUNCTIONS*/
void getTextInput(char *inString, int strLen); //takes a reference to a cstring and populates the string with valid input

double getNumInput(); //returns a valid double from user input

double getNumInput(double min, double max); //gets input from user using getNumInput(), with bounds checking

void displayProduct(Product currentProduct); //takes in a product struct and prints it, formatted

double runningTotal(Product* cart, int size); //add up the prices of all the items in the cart and returns subtotal

void displayCart(Product* cart, int size); //calls displayProduct() for each Product in cart to print out the cart

int main()
{
	struct Product shoppingCart[100];
	int cartSize = 0;
	
	bool readyToCheckOut = false;
	do {
		/*Prompt for product to add to cart*/
		char prodName[MAX_LENGTH];
		cout << "Please enter a product name:";
		getTextInput(prodName, MAX_LENGTH); //use getTextInput to retrieve product name
		shoppingCart[cartSize].productName = prodName; //store the productName to the Product in the cart

		cout << "Please enter the price: ";
		shoppingCart[cartSize].cost = getNumInput(0, 9999); //use getNumInput to retrieve a valid price from the user

		/*Echo the product back to the user*/
		displayProduct(shoppingCart[cartSize]);

		/*Add the product to the cart*/
		cartSize++;
		
		/*Prompt for checkout*/
		cout << "Press 1 to add more items or 2 to check out." << endl;
		if (getNumInput() == 2) readyToCheckOut = true;
	} while (!readyToCheckOut);

	/*CHECKOUT*/
	displayCart(shoppingCart, cartSize);
	cout << "SUBTOTAL:   " << runningTotal(shoppingCart, cartSize) << endl;
	cout.setf(ios::fixed, ios::floatfield); cout.setf(ios::showpoint); cout.precision(2);
	cout << "GRAND TOTAL @" << TAX_RATE * 100 << "% tax :   " << TAX_RATE * runningTotal(shoppingCart, cartSize)+ runningTotal(shoppingCart, cartSize);

	return 0;
	

	
}


void getTextInput(char* inString, int strLen)
{
	cin.get(inString, strLen);
	while(!cin) //check if the input failed during data retrieval
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
	while(!cin)
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
	double output = -999.99;
	output = getNumInput();	
	while(output < min || output > max)		//check that output is within bounds
	{
		cout << "The number must be between " << min << " and " << max << endl;
		cout << "Please try again: ";
		output = getNumInput();
	}
	return output;
}

void displayProduct(Product currentProduct)
{
	cout.setf(ios::fixed, ios::floatfield); cout.setf(ios::showpoint); cout.precision(2); //set formatting
	cout << left << setw(20) << currentProduct.productName << "  |  "; //output product name
	cout << setw(10) << "$" << currentProduct.cost << endl;  //output the cost
	
}

double runningTotal(Product* cart, int size)
{
	double total = 0;
	Product* p = cart;
	for(int i = 0; i < size; p++, i++)	//iterate through the cart
	{
		Product current = *p;
		total += current.cost; //add the cost to the running total
	}

	//output the total
	return total;
}



void displayCart(Product* cart, int size)
{
	Product* p = cart;
	for (int i = 0; i < size; p++, i++)	//iterate through the cart
	{
		displayProduct(*p);
	}
}

