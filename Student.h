#pragma once
#include "Degree.h"
#include <string>
using namespace std;

class Student
{
public:
	// Value constructor
	Student(string id, string fName, string lName, string email, \
		int yearsOld, int days1, int days2, int days3);
	Student();	// Default constructor
	~Student();	/ Destructor

	// Accessors
	string getStudentID();
	string getFirstName();
	string getLastName();
	string getEmailAddress();
	int getAge();
	int getDaysToComplete(int i);	// Returns daysToComplete value at index i

	// Mutators
	void setStudentID(string id);
	void setFirstName(string name);
	void setLastName(string name);
	void setEmailAddress(string email);
	void setAge(int yearsOld);
	void setDaysToComplete(int days1, int days2, int days3);

	virtual void print();				// Print Student's information
	virtual Degree getDegreeProgram() = 0;		// Return degreeType

private:
	string studentID;
	string firstName;
	string lastName;
	string emailAddress;
	int age;
	int daysToComplete[3];
};

