#pragma once
#include "student.h"
#include <iostream>
#include <iomanip>
using namespace std;



Student::Student() {
	this->studentID = "";
	this->firstName = "";
	this->lastName = "";
	this->email = "";
	this->age = 0;
	for (int i = 0; i < daysArraySize; ++i) this->days[i] = 0;
	this->degreeProgram = DegreeProgram::UNDECIDED;
}

Student::Student(string studentID, string firstName, string lastName, string email, int age, int days[], DegreeProgram degreeProgram) {
	this->studentID = studentID;
	this->firstName = firstName;
	this->lastName = lastName;
	this->email = email;
	this->age = age;
	for (int i = 0; i < daysArraySize; ++i) this->days[i] = days[i];
	this->degreeProgram = degreeProgram;
}

Student::~Student() {}

string Student::GetID() { return this->studentID; }
string Student::GetFirstName() { return this->firstName;  }
string Student::GetLastName() { return this->lastName;  }
string Student::GetEmail() { return this->email;  }
int Student::GetAge() { return this->age;  }
int* Student::GetDays() { return this->days;  }
DegreeProgram Student::GetDegreeProgram() { return this->degreeProgram; }

void Student::SetID(string ID) { this->studentID = ID; }
void Student::SetFirstName(string firstName) { this->firstName = firstName; }
void Student::SetLastName(string lastName) { this->lastName = lastName; }
void Student::SetEmail(string email) { this->email = email; }
void Student::SetAge(int age) { this->age = age; }
void Student::SetDays(int days[]) {
	for (int i = 0; i < daysArraySize; ++i) { this->days[i] = days[i]; }
}
void Student::SetDegreeProgram(DegreeProgram dp) { this->degreeProgram = dp; }

void Student::PrintHeader() {
	cout << "Output format: Student ID|First Name|Last Name|Email|Age|Days in Course|Degree Program" << endl;
}

void Student::Print() {
	cout << this->GetID() << ' ';
	cout << this->GetFirstName() << ' ';
	cout << this->GetLastName() << ' ';
	cout << this->GetEmail() << ' ';
	cout << this->GetAge() << ' ';
	cout << this->GetDays()[0] << ',';
	cout << this->GetDays()[1] << ',';
	cout << this->GetDays()[2] << ' ';
	cout << degreeProgramStrings[this->GetDegreeProgram()] << endl;
}