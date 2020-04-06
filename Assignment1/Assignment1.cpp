/*
	Program: Assignment 1
	Author: Matthew Loera
	Date: 4/5/20
	Description: This program adds Products into the Shopping Cart and prints out a running total each time.
	When the user checks out, this program prints an itemized receipt as well as the total. 
*/

#include <iostream>
using namespace std;

/*CONSTANTS*/
const int MAX_LENGTH = 30; //maximum length of the cstrings
const double TAX_RATE = 0; //tax rate

/*DATA STRUCTURES*/
struct Product
{
	char* productName;
	int strLen; //name length
	double cost;
};

/*FUNCTIONS*/
char* getTextInput(char *inString, int strLen); //takes a reference to a cstring and populates the string with valid input

double getNumInput(); //returns a valid double from user input

double getNumInput(double min, double max); //gets input from user using getNumInput(), with bounds checking

void displayProduct(Product currentProduct); //takes in a product struct and prints it, formatted

double runningTotal(Product* cart, int size); //add up the prices of all the items in the cart and returns subtotal

void addToCart(Product addItem, Product* cart, int size); //adds addItem to the cart
														  //don't forget to increment the cart size

void displayCart(Product* cart, int size); //calls displayProduct() for each Product in cart to print out the cart

int main()
{
    std::cout << "Hello World!\n";
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file

char* getTextInput(char* inString, int strLen)
{
	return nullptr;
}

double getNumInput()
{
	return 0.0;
}

double getNumInput(double min, double max)
{
	return 0.0;
}

void displayProduct(Product currentProduct)
{
}

double runningTotal(Product* cart, int size)
{
	return 0.0;
}

void addToCart(Product addItem, Product* cart, int size)
{
}

void displayCart(Product* cart, int size)
{
}
