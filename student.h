#pragma once
#ifndef STUDENT_H
#define STUDENT_H
#include <string>
#include "degree.h"
using namespace std;

class student {

private:
	//variables
	string studentID;
	string firstName;
	string lastName;
	string email;
	int age;
	int numberofDays[3];
	Degree degreeP;

public:

	// default constructor
	student();
	void print();


	//constructor with parameters
	student(string sID, string firstN, string lastN, string emailAdd, int addAge, int* noDays, Degree degreeProg);

	//setters and getters
	void SetStudentID(string setstudentID);
	string GetStudentID() const;
	
	void SetFirstName(string setfirstName);
	string GetFirstName() const;
	
	void SetLastName(string setlastName);
	string GetLastName() const;

	void SetEmailAddress(string setemailAddress);
	string GetEmailAddress() const;

	void SetAge(int setAge);
	int GetAge() const;

	void SetDegreeProgram(Degree setdegreeProgram);
	string GetDegreeProgram() const;

	void SetNumberOfDays(int class1, int class2, int class3);
	int *GetNumberOfDays();
	
	



	


};
#endif