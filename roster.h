#pragma once
#include "student.h"
#include "student.cpp"
class Roster {

private: 
	int lastIndex = -1;
	const static int numStudents = 5;
	Student* studentRosterArray[numStudents];

public:
	void Parse(string row);
	void Add(string studentID,
		string firstName,
		string lastName,
		string emailAddress,
		int age,
		int daysInCourse1,
		int daysInCourse2,
		int daysInCourse3,
		DegreeProgram degreeprogram);
	void PrintAll();
	void PrintByDegreeProgram(DegreeProgram degreeprogram);
	void RemoveByID(string studentID);
	void PrintAverageDaysInCourse(string studentID);
	void PrintInvalidEmails(); //A valid email should include an @ sign and period '.' and should not include a space.
	~Roster();
};

