#ifndef STUDENT_H
#define STUDENT_H

#include <iostream>
#include <cstring>
using namespace std;

class Student
{
public:

	//Initialized constructor for Student object
	//POSTCONDITION: initID = id, gpa = gpa
	Student(const char initId[], double gpa);

	//function that compares the calling student to the referenced student aStudent
	//POSTCONDITION: returns true if the calling Student is less than aStudent
	bool isLessThanByID(const Student& aStudent) const;

	//function that checks if the Student qualifies for honors based on minGpaForHonor
	//POSTCONDTION: returns true if minGpaForHonor <= gpa
	bool qualifyForHonor(double minGpaForHonor) const;

	//function that displays the student object to stdout
	void print()const;

private:
	const static int MAX_CHAR = 100;
	char 	id[MAX_CHAR];
	double	gpa;
};
#endif
