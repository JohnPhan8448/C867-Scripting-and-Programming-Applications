#include <iostream>
#include <string>
using namespace std;

#include "student.h"
#include "degree.h"


//default constructor
student::student() {
	
	studentID = "NONE";
	age = -1;
	firstName = "NOFIRSTNAME";
	lastName = "NOLASTNAME";
	email = "NOEMAIL";
	for (int i = 0; i < 3; ++i) {
		numberofDays[i] = 0;
	}
}


//constructor with parameters
student::student(string sID, string firstN, string lastN, string emailAdd, int addAge, int* noDays, Degree degreeProg) {
	studentID = sID;
	firstName = firstN;
	lastName = lastN;
	email = emailAdd;
	age = addAge;
	numberofDays[0] = noDays[0];
	numberofDays[1] = noDays[1];
	numberofDays[2] = noDays[2];
	degreeP = degreeProg;
}


//prints information on student
void student::print() {
	cout << "Student ID: " << GetStudentID() << endl;
	cout << "Student Name: " << GetFirstName() << " " << GetLastName() << endl;
	cout << "Age: " << GetAge() << endl;
	cout << "Email Address: " << GetEmailAddress() << endl;
	cout << "Degree Program: " << GetDegreeProgram() << endl;
	cout << "Days in class " << numberofDays[0] << " " << numberofDays[1] << " " << numberofDays[2] << endl <<endl;
}


//set and get student ID
void student::SetStudentID(string setstudentID) {
	studentID = setstudentID;
}

string student::GetStudentID() const {
	return studentID;
}

//set and get first name
void student::SetFirstName(string setfirstName) {
	firstName = setfirstName;
}

string student::GetFirstName() const {
	return firstName;
}

//set and get last name
void student::SetLastName(string setlastName) {
	lastName = setlastName;
}

string student::GetLastName() const {
	return lastName;
}

//set and get email
void student::SetEmailAddress(string setemailAddress) {
	email = setemailAddress;
}

string student::GetEmailAddress() const {
	return email;
}

//set and get age
void student::SetAge(int setAge) {
	age = setAge;
}

int student::GetAge() const {
	return age;
}

//set and get number of days in each class
void student::SetNumberOfDays(int class1, int class2, int class3) {
	numberofDays[0] = class1;
	numberofDays[1] = class2;
	numberofDays[2] = class3;
}

int* student::GetNumberOfDays() {
	return numberofDays;
}


//set and get degree program
void student::SetDegreeProgram(Degree setdegreeProgram) {
	degreeP = setdegreeProgram;
}

string student::GetDegreeProgram() const {
	string network = "NETWORK";
	string software = "SOFTWARE";
	string security = "SECURITY";
	string error = "ERROR";
	
	//converts enum into string, and returns string for print function.
	if ((int)degreeP == 0) {
		return security;
	}
	else if ((int)degreeP == 1) {
		return network;
	}
	else if ((int)degreeP == 2) {
		return software;
	}
	else {
		return error;
	}
}