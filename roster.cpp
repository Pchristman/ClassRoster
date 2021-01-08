#pragma once
#include <iostream>
#include <string>
#include <regex>
#include "roster.h"
#include "student.cpp"
using namespace std;


void Roster::Add(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram dp) {

	int dayArray[3] = { daysInCourse1, daysInCourse2, daysInCourse3 };

	studentRosterArray[++lastIndex] = new Student(studentID, firstName, lastName, emailAddress, age, dayArray, dp);
}


void Roster::Parse(string studentData) {

	int rhs = studentData.find(",");
	string studentID = studentData.substr(0, rhs);

	int lhs = rhs + 1;
	rhs = studentData.find(",", lhs);
	string firstName = studentData.substr(lhs, rhs - lhs);

	lhs = rhs + 1;
	rhs = studentData.find(",", lhs);
	string lastName = studentData.substr(lhs, rhs - lhs);

	lhs = rhs + 1;
	rhs = studentData.find(",", lhs);
	string email = studentData.substr(lhs, rhs - lhs);

	lhs = rhs + 1;
	rhs = studentData.find(",", lhs);
	int age = stoi(studentData.substr(lhs, rhs - lhs));

	lhs = rhs + 1;
	rhs = studentData.find(",", lhs);
	int days1 = stoi(studentData.substr(lhs, rhs - lhs));
	lhs = rhs + 1;
	rhs = studentData.find(",", lhs);
	int days2 = stoi(studentData.substr(lhs, rhs - lhs));
	lhs = rhs + 1;
	rhs = studentData.find(",", lhs);
	int days3 = stoi(studentData.substr(lhs, rhs - lhs));

	lhs = rhs + 1;
	DegreeProgram dp = SOFTWARE; //Default Value
	if (studentData.at(lhs + 1) == 'E') { dp = SECURITY; }
    if (studentData.at(lhs) == 'N') { dp = NETWORK; }
	

	Add(studentID, firstName, lastName, email, age, days1, days2, days3, dp);
}

void Roster::PrintAll() {
	for (int i = 0; i <= this->lastIndex; ++i) {
		(this->studentRosterArray)[i]->Print();
	}
	cout << endl;
}

void Roster::PrintByDegreeProgram(DegreeProgram dp) {
	for (int i = 0; i <= Roster::lastIndex; ++i) {
		if (Roster::studentRosterArray[i]->GetDegreeProgram() == dp) {
			studentRosterArray[i]->Print();
		}
	}
	cout << endl;
}

void Roster::PrintInvalidEmails() {
	bool any = false;
	for (int i = 0; i <= Roster::lastIndex; ++i) {
		string email = (studentRosterArray[i]->GetEmail());
		if (email.find('@') == string::npos || email.find('.') == string::npos || !(email.find(' ') == string::npos)) {
			any = true;
			cout << studentRosterArray[i]->GetFirstName() << " " << studentRosterArray[i]->GetLastName();
			cout << ": " << studentRosterArray[i]->GetEmail() << endl;
		}
	}
	if (!any) { cout << "NONE" << endl; }
}

void Roster::PrintAverageDaysInCourse(string studentID) {
	for (int i = 0; i <= Roster::lastIndex; ++i) {
		if (this->studentRosterArray[i]->GetID() == studentID) {
			cout << studentRosterArray[i]->GetID() << ": ";
			cout << (studentRosterArray[i]->GetDays()[0] + studentRosterArray[i]->GetDays()[1]
				+ studentRosterArray[i]->GetDays()[2]) / 3.0 << endl;
		}
	}
	cout << endl;
}

void Roster::RemoveByID(string studentID) {
	bool success = false;
	for (int i = 0; i <= Roster::lastIndex; ++i) {
		if (studentRosterArray[i]->GetID() == studentID) {
			success = true;
			if (i < numStudents - 1) {
				Student* temp = studentRosterArray[i];
				studentRosterArray[i] = studentRosterArray[numStudents - 1];
				studentRosterArray[numStudents - 1] = temp;
			}
			Roster::lastIndex--;
		}
	}
	if (success) {
		cout << studentID << " removed from roster." << endl << endl;
		this->PrintAll();
	}
	else {
		cout << studentID << " not found." << endl << endl;
	}
}

Roster::~Roster() {
	cout << "DESTRUCTOR CALLED!" << endl << endl;
	for (int i = 0; i < numStudents; ++i) {
		cout << "Destroying student #" << i + 1 << endl;
		delete studentRosterArray[i];
		studentRosterArray[i] = nullptr;
	}
}