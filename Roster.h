#pragma once
#include "Degree.h"
#include "Student.h"
#include "SecurityStudent.h"
#include "NetworkStudent.h"
#include "SoftwareStudent.h"

class Roster
{
public:
	Roster();	// Default constructor
	~Roster();	// Destructor
	
	// Return pointer to Student object at index i
	Student* getRosterElement(int i);
	
	// Add new Student to classRosterArray
	void add(string studentID, string firstName, string lastName, string emailAddress, \
		     int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, \
		     Degree degType, int location);
	
	// Remove Student with id studentID
	void remove(string studentID);
	
	// Print information for all Students in classRosterArray
	void printAll();
	
	// Calculate and print the average number of days left in the courses
	void printAverageDaysInCourse(string studentID);
	
	// Print all emails that are invalid
	void printInvalidEmails();
	
	// Print all Student information for Students with degreeType of degreeProgram
	void printByDegreeProgram(int degreeProgram);

private:
	Student *classRosterArray[5];
};

