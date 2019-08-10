#pragma once
#include "Degree.h"
#include "Student.h"
#include "SecurityStudent.h"
#include "NetworkStudent.h"
#include "SoftwareStudent.h"

class Roster
{
public:
	Roster();
	~Roster();
	Student* getRosterElement(int i);
	void add(string studentID, string firstName, string lastName, string emailAddress, \
		     int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, \
		     Degree degType, int location);
	void remove(string studentID);
	void printAll();
	void printAverageDaysInCourse(string studentID);
	void printInvalidEmails();
	void printByDegreeProgram(int degreeProgram);

private:
	Student *classRosterArray[5];
};

