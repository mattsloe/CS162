#include "student.h"

class StudentList
{
public:
	StudentList();
	~StudentList();
	//StudentList(const StudentList& aList); //your exercise

	void addStudent(const Student& aStudent);
	void listAll() const;
	void loadStudents(const char fileName[]);
	void saveStudents(const char fileName[]) const;
	//void operator= (const StudentList& aList); //your exercise

private:
	const static int INIT_CAP = 1;
	const static int GROWTH_FACTOR = 2;
	Student ** 	list;
	int			currCapacity;
	int			size;
	
	void expandList();
};	

