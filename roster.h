#pragma once
#include <iostream>
#include <string>
using namespace std;

#include "student.h"
#include "degree.h"


class Roster {

private:
	student* classrosterArr[5] = { nullptr, nullptr, nullptr, nullptr, nullptr };
	int studentCount = 0;


public:
	
	~Roster();

	void add(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse1, int daysinCourse2, int daysIncourse3, Degree degreeProg);
	void remove(string studentID);
	void printAll();
	void printAverageDaysInCourse(string studentID);
	void printInvalidEmails();
	void printByDegreeProgram(Degree degreeProgram);

};
