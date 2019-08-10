#include "SoftwareStudent.h"
#include <string>
#include <iostream>
using namespace std;

// Default constructor, sets degreeType to SOFTWARE
SoftwareStudent::SoftwareStudent()
{
	degreeType = SOFTWARE;
}

// Destructor
SoftwareStudent::~SoftwareStudent()
{
}

// Returns degreeType
Degree SoftwareStudent::getDegreeProgram() {
	return degreeType;
}

// Prints the SoftwareStudent's information
void SoftwareStudent::print() {
	cout << this->getStudentID() << '\t';
	cout << "First Name: " << this->getFirstName() << '\t';
	cout << "Last Name: " << this->getLastName() << '\t';
	cout << "Age: " << this->getAge() << '\t';
	cout << "daysInCourse: " << '{' << this->getDaysToComplete(0) << ", " << \
		this->getDaysToComplete(1) << ", " << this->getDaysToComplete(2) << '}' << '\t';
	cout << "Degree Program: SOFTWARE" << endl;
}
