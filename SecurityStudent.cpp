#include "SecurityStudent.h"
#include <string>
#include <iostream>
using namespace std;


SecurityStudent::SecurityStudent()
{
	degreeType = SECURITY;
}


SecurityStudent::~SecurityStudent()
{
}


Degree SecurityStudent::getDegreeProgram() {
	return degreeType;
}


void SecurityStudent::print() {
	cout << this->getStudentID() << '\t';
	cout << "First Name: " << this->getFirstName() << '\t';
	cout << "Last Name: " << this->getLastName() << '\t';
	cout << "Age: " << this->getAge() << '\t';
	cout << "daysInCourse: " << '{' << this->getDaysToComplete(0) << ", " << \
		this->getDaysToComplete(1) << ", " << this->getDaysToComplete(2) << '}' << '\t';
	cout << "Degree Program: SECURITY" << endl;
}