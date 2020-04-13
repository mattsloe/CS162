#include <iostream>
#include <cstring>

using namespace std;

const int MAX_CHAR = 100; //max string size
const int MIN_A = 90; //minimum grade for A
const int MIN_B = 80; //minimum grade for B
const int MIN_C = 70; //minimum grade for C

/*FUNCTIONS*/
double getAvg(); //prompts user for average score
char determineGrade(double finalAvg); //determines the user's letter grade based on numerical
void printMsg(char grade); //prints the letter grade to the screen

int main()
{
	double	score;
	char	grade;

	score = getAvg(); //use getAvg() to prompt user for numerical score
	grade = determineGrade(score); //uses score to determine a letter grade
	printMsg(grade);

	return 0;
}

double getAvg()
{
	double finalAvg;

	cout << "Please enter your final average: ";
	cin >> finalAvg;
	while(!cin)
	{
		cin.clear();
		cin.ignore(MAX_CHAR, '\n');
		cout << "input has to be numerical!" << endl;
		cin >> finalAvg;
	}
	cin.ignore(MAX_CHAR, '\n');
	return finalAvg;
}
char determineGrade(double finalAvg)
{
	char grade = 'F';	
	if(finalAvg >= MIN_A)
	{
		grade = 'A';	
	}
	else if(finalAvg >= MIN_B)
	{
		grade = 'B';
	}
	else if(finalAvg >= MIN_C);
	{
		grade = 'C';
	}

	return grade;
}
void printMsg(char grade)
{
	char	msg[MAX_CHAR];
	switch(grade)
	{
		case 'A':
			strcpy(msg, "Excellent!");
			break;
		case 'B':
			strcpy(msg, "Good job!");
			break;
		case 'C':
			strcpy(msg, "You've passed!");
			break;
		default:
			strcpy(msg, "Need to put down that video game!");
			break;
	}
	cout << msg << endl;
}
