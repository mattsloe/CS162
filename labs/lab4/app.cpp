#include "student.h"

int main()
{
	Student s1("G10", 3.9); //Initialize s1 (ID: G10, GPA: 3.9)
	Student s2("G20", 3.5); //Initialize s2 (ID: G20, GPA: 3.5)

	s1.print(); //display s1
	s2.print(); //display s2

	//write code to test Student::isLessThanByID
	if(s1.isLessThanByID(s2)){
		cout << "Student 1 " << "is less than" << " Student 2" << endl;
	}
	else{
		cout << "error" << endl;
	}
	//write code to test Student::qualifyForHonor
	double minHonorGPA = 3.5; //minimum gpa requirement for honors
	//CASE 1: Min Honor GPA = 3.5
	cout << "If minimum GPA for Honors is 3.5:\n";
	if (s1.qualifyForHonor(minHonorGPA)){ //Test s1 for honors qual
		cout << "Student 1 qualifies for Honors" << endl;
	}

	if (s2.qualifyForHonor(minHonorGPA)){ //Test s2 for honors qual
		cout << "Student 2 qualifies for Honors" << endl;
	}
	
	//CASE 2: Min Honor GPA = 3.8
	cout << "If minimum GPA for Honors is 3.8:\n";
	minHonorGPA = 3.8;
	if (s1.qualifyForHonor(minHonorGPA)){ //Test s1 for honors qual
		cout << "Student 1 qualifies for Honors" << endl;
	}

	if (s2.qualifyForHonor(minHonorGPA)){ //Test s2 for honors qual
		cout << "Student 2 qualifies for Honors" << endl;
	}	
	return 0;
}
