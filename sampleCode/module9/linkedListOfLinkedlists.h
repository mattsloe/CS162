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
	struct CourseNode
	{
		CourseNode (const Course& aCourse)
		{
			data = aCourse;
			next = nullptr;
		}
		Course 			data;
		CourseNode * 	next;
	};
	
	struct StudentNode
	{
		StudentNode (const Student& aStudent)
		{
			data = aStudent; //assuming operator= is overloaded for Student
			next = nullptr;
			headCourse = nullptr;
		}
		Student data;
		StudentNode *	next;
		CourseNode *	headCourse;
		int				numOfCourses;
	};
	 
	StudentNode * head;
	int		size;

};	

