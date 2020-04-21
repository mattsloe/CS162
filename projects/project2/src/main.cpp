//
//  main.cpp
//  Program Desciption: Add student to database, delete student from the database and print database.
//
//  Created by Shawli on 4/8/20.
//  Copyright © 2020 Shawli. All rights reserved.
//

//Include header files
#include <iostream>
#include<cstring>
#include<cctype>
#include<iomanip>

using namespace std;

//Declare constant
const int ARRSIZE = 50;
const int STRSIZE = 50;

//Struct specification
struct StudentType
{
    //Member Variable
    char studName[STRSIZE];
    int id = 0;
    double gpa = 0;
    //Member Function
    void readDB();
    void listDB();

};

void addDB(StudentType student[], int& count);
void deleteDB(StudentType student[], int& count);
void printDB(StudentType student[], const int count);

int main() {
    // insert code here...
    StudentType student[ARRSIZE];
    int count = 0;

    addDB(student, count);
    printDB(student, count);
    deleteDB(student, count);
    printDB(student, count);

    return 0;
}

void StudentType::readDB()
{
    cout << "Please enter student name" << endl;
    cin.getline(studName, STRSIZE, '\n');
    cout << "Please enter student id" << endl;
    cin >> id;
    cout << "Please enter student gpa" << endl;
    cin >> gpa;
}

void StudentType::listDB()
{
    cout << fixed << setprecision(2);
    cout << left << setw(15) << studName << setw(7) << id << setw(5) << gpa << endl;

}

void addDB(StudentType student[], int& count)
{

    char response[4] = "yes";
    while ((strcmp(response, "no") != 0))
    {
        student[count].readDB();
        count++;
        cout << "Do you want to continue? Enter yes or no." << endl;
        cin.ignore(5, '\n');
        cin.getline(response, 4);
    }

}

void deleteDB(StudentType student[], int& count)
{
    int delnum;
    cout << "Enter the index number you want to delete" << endl;
    cin >> delnum;
    for (int i = delnum; i < count; i++)
    {
        student[i - 1] = student[i];
    }
    count--;
}

void printDB(StudentType student[], const int count)
{
    cout << left << setw(6) << "Index" << setw(15) << "Student" << setw(7) << "ID" << setw(5) << "GPA" << endl;
    int index = 1;
    for (int i = 0; i < count; i++)
    {
        cout << left << setw(6) << index;
        student[i].listDB();
        index++;
    }
}
