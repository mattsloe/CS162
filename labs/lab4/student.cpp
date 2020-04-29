#include "student.h"

//implement the required 3 functions here
Student::Student(const char initId[], double gpa)
{
	Student::gpa = gpa;
	strcpy(Student::id,initId);
}

bool Student::isLessThanByID(const Student& aStudent) const
{
	if(strcmp(id,aStudent.id) < 0) return true;
	return false;
}

bool Student::qualifyForHonor(double minGpaForHonor) const
{
	if(gpa >= minGpaForHonor) return true;
	return false;
}

void Student::print() const
{
	cout << id << '\t' << gpa << endl;
}
