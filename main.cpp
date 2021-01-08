#include <iostream>
#include <string>
#include <cmath>
#include "degree.h"
#include "student.h"
#include "student.cpp"
#include "roster.h"
#include "roster.cpp"
using namespace std;

int main()
{
    cout << "C867, C++, ID: 001524778, Paul Christman" << endl << endl;
    const string studentData[] =
    { "A1,John,Smith,John1989@gmail.com,20,30,35,40,SECURITY"
      "A2,Suzan,Erickson,Erickson_1990@gmail.com,19,50,30,40,NETWORK"
      "A3,Jack,Napoli,The_lawyer99@yahoo.com,19,20,40,33,SOFTWARE"
      "A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY"
      "A5,Paul,Christman,pchristman1@outlook.com,22,28,25,SOFTWARE"
    };

    const int numStudents = 5;
    Roster classRoster;

    for (int i = 0; i < numStudents; ++i) {
        classRoster.Parse(studentData[i]);
    }
    cout << "Displaying all students: " << endl;
    classRoster.PrintAll();
    cout << endl;

    cout << "Displaying students with invalid emails" << endl;
    classRoster.PrintInvalidEmails();
    cout << endl;

    cout << "Displaying average days in courses for student with ID A3 " << endl;
    classRoster.PrintAverageDaysInCourse("A3");

    cout << "Displaying by degree program (Software): ";
    classRoster.PrintByDegreeProgram(DegreeProgram SOFTWARE);

    classRoster.RemoveByID("A3");

    cout << "Displaying all students: " << endl;
    classRoster.PrintAll();
    cout << endl;

    classRoster.RemoveByID("A3");


    system("pause");
    return 0;

}