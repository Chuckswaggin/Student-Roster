#include "SecurityStudent.h"
#include <string>
#include <iostream>
using namespace std;

// Default constructor, sets degreeType to SECURITY
SecurityStudent::SecurityStudent()
{
	degreeType = SECURITY;
}

// Destructor
SecurityStudent::~SecurityStudent()
{
}

// Return degreeType
Degree SecurityStudent::getDegreeProgram() {
	return degreeType;
}

// Prints the SecurityStudent's information
void SecurityStudent::print() {
	cout << this->getStudentID() << '\t';
	cout << "First Name: " << this->getFirstName() << '\t';
	cout << "Last Name: " << this->getLastName() << '\t';
	cout << "Age: " << this->getAge() << '\t';
	cout << "daysInCourse: " << '{' << this->getDaysToComplete(0) << ", " << \
		this->getDaysToComplete(1) << ", " << this->getDaysToComplete(2) << '}' << '\t';
	cout << "Degree Program: SECURITY" << endl;
}
