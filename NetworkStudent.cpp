#include "NetworkStudent.h"
#include <string>
#include <iostream>
using namespace std;

// Default constructor, sets degreeType to NETWORKING
NetworkStudent::NetworkStudent()
{
	degreeType = NETWORKING;
}

// Destructor
NetworkStudent::~NetworkStudent()
{
}

// Getter for degreeType
Degree NetworkStudent::getDegreeProgram() {
	return degreeType;
}

// Print the NetworkStudents information
void NetworkStudent::print() {
	cout << this->getStudentID() << '\t';
	cout << "First Name: " << this->getFirstName() << '\t';
	cout << "Last Name: " << this->getLastName() << '\t';
	cout << "Age: " << this->getAge() << '\t';
	cout << "daysInCourse: " << '{' << this->getDaysToComplete(0) << ", " << \
		this->getDaysToComplete(1) << ", " << this->getDaysToComplete(2) << '}' << '\t';
	cout << "Degree Program: NETWORK" << endl;
}
