#pragma once
#include <iostream>
#include <string>
#include <iomanip>
#include "degree.h"
using namespace std;

class Student {
	public:
		const static int daysArraySize = 3;
	private:
		string studentID;
		string firstName;
		string lastName;
		string email;
		int age;
		int days[daysArraySize];
		DegreeProgram degreeProgram;
	public: 
		Student(); //Base Constructor (default values)
		Student(string studentID, string firstName, string lastName, string email, int age, int days[], DegreeProgram degreeProgram);//Full Constructor
		~Student(); //Destructor
		
		//Getters/Accessors
		string GetID();
		string GetFirstName();
		string GetLastName();
		string GetEmail();
		int GetAge();
		int* GetDays();
		DegreeProgram GetDegreeProgram();

		//Setters/Mutators
		void SetID(string ID);
		void SetFirstName(string firstName);
		void SetLastName(string lastName);
		void SetEmail(string email);
		void SetAge(int age);
		void SetDays(int days[]);
		void SetDegreeProgram(DegreeProgram dp);

		static void PrintHeader();

		void Print();
};


