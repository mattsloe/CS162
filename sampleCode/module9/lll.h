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
	struct Node
	{
		Node (const Student& aStudent)
		{
			data = aStudent; //assuming operator= is overloaded for Student
			next = nullptr;
		}
		Student data;
		Node *	next;
	};
	Node * 	head;
	Node * 	tail;
	int		size;

	void insertAtBeginning(const Student& aStudent);
	void append(const Student& aStudent);
	void insertSortedByGpa(const Student& aStudent);
};	

