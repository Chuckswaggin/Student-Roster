#include "SoftwareStudent.h"
#include <string>
#include <iostream>
using namespace std;


SoftwareStudent::SoftwareStudent()
{
	degreeType = SOFTWARE;
}


SoftwareStudent::~SoftwareStudent()
{
}


Degree SoftwareStudent::getDegreeProgram() {
	return degreeType;
}


void SoftwareStudent::print() {
	cout << this->getStudentID() << '\t';
	cout << "First Name: " << this->getFirstName() << '\t';
	cout << "Last Name: " << this->getLastName() << '\t';
	cout << "Age: " << this->getAge() << '\t';
	cout << "daysInCourse: " << '{' << this->getDaysToComplete(0) << ", " << \
		this->getDaysToComplete(1) << ", " << this->getDaysToComplete(2) << '}' << '\t';
	cout << "Degree Program: SOFTWARE" << endl;
}