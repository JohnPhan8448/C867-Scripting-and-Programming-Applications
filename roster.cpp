#pragma once
#include <iostream>
#include <string>
using namespace std;


#include "student.h"
#include "degree.h"
#include "roster.h"


//add students into the roster class
void Roster::add(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse1, int daysinCourse2, int daysIncourse3, Degree degreeProg) {
	
	int averageDays[3] = { daysInCourse1,daysinCourse2,daysIncourse3 };
	classrosterArr[studentCount] = new student(studentID, firstName, lastName, emailAddress, age, averageDays, degreeProg);
	++studentCount;
}

//removes student using student's ID
void Roster::remove(string studentID) {
	
	bool studentwasRemoved = false;
	int i = 0;

	for (i = 0; i < 5; ++i) {	
		if (classrosterArr[i] != NULL) {

			if (classrosterArr[i]->GetStudentID() == studentID) {
				classrosterArr[i] = nullptr;
				studentwasRemoved = true;
			}
		}
	}

	//checks to see if a student was removed.
	if (studentwasRemoved == false) {
		cout << "student with this ID was not found." << endl;
	}
}

//prints all students in roster
void Roster::printAll() {
	cout << "PrintAll: " << endl << endl;
	int i = 0;
	for (i = 0; i < 5; ++i) {
		if (classrosterArr[i] != NULL) {
			classrosterArr[i]->print();
			cout << endl << endl;
		}
	}

}

//prints average days in the three courses
void Roster::printAverageDaysInCourse(string studentID) {
	
	int i = 0;

	for (i = 0; i < 5; ++i) {
		if (classrosterArr[i]->GetStudentID() == studentID)
		{
			int average = 0;
			average = (classrosterArr[i]->GetNumberOfDays()[0] + classrosterArr[i]->GetNumberOfDays()[1] + classrosterArr[i]->GetNumberOfDays()[2]) / 3;
			cout << "student ID: " << studentID << " Average days it took to complete courses: " << average << endl << endl;
		}
	}
}

//searches for invald emails without '@' and '.' and also searches emails WITH spaces
void Roster::printInvalidEmails() {
	int i = 0;

	for (int i = 0; i < 5; ++i) {
		string invalidEmail = classrosterArr[i]->GetEmailAddress();

		if (invalidEmail.find("@") == -1 || invalidEmail.find(".") == -1 || invalidEmail.find(" ") != -1)  {
			cout << invalidEmail << " is not a valid email." << endl << endl;
		}
	}
}

//prints by degree program.
void Roster::printByDegreeProgram(Degree degreeProgram) {
	int i = 0;
	Degree d = degreeProgram;
	string degree;
	
	//assigns a string with the corresponding enum value.
	if (d == 0) {
		degree = "SECURITY";
	}
	else if (d == 1) {
		degree = "NETWORK";
	}
	else if (d == 2) {
		degree = "SOFTWARE";
	}

	cout << "Students in " << degree << " program:" << endl << endl;

	//prints depending on which degree.
	for (int i = 0; i < 5; ++i) {
		if (classrosterArr[i]->GetDegreeProgram() == degree) {
			classrosterArr[i]->print();
		}
	}
}

Roster::~Roster() {
		int i = 0;
		for (i = 0; i < 5; ++i) {
			if (classrosterArr[i] != nullptr) {
				delete classrosterArr[i];
			}
		}
}
