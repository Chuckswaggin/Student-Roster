#include "Student.h"
#include <iostream>
using namespace std;


// Constructor
Student::Student() {
	daysToComplete[0] = 0;
	daysToComplete[1] = 0;
	daysToComplete[2] = 0;
}

// Value constructor
Student::Student(string id, string fName, string lName, string email, \
	int yearsOld, int days1, int days2, int days3) {
	studentID = id;
	firstName = fName;
	lastName = lName;
	emailAddress = email;
	age = yearsOld;
	daysToComplete[0] = days1;
	daysToComplete[1] = days2;
	daysToComplete[2] = days3;

	return;
}

// Destructor
Student::~Student()
{
	return;
}

// Accessors
string Student::getStudentID() {
	return studentID;
}

string Student::getFirstName() {
	return firstName;
}

string Student::getLastName() {
	return lastName;
}

string Student::getEmailAddress() {
	return emailAddress;
}

int Student::getAge() {
	return age;
}

int Student::getDaysToComplete(int i) {
	return daysToComplete[i];
}

// Mutators
void Student::setStudentID(string id) {
	studentID = id;
	return;
}

void Student::setFirstName(string name) {
	firstName = name;
	return;
}

void Student::setLastName(string name) {
	lastName = name;
	return;
}

void Student::setEmailAddress(string email) {
	emailAddress = email;
	return;
}

void Student::setAge(int yearsOld) {
	age = yearsOld;
	return;
}

void Student::setDaysToComplete(int days1, int days2, int days3) {
	daysToComplete[0] = days1;
	daysToComplete[1] = days2;
	daysToComplete[2] = days3;
	return;
}

// Print the Student's information
void Student::print() {
	cout << this->getStudentID() << '\t';
	cout << "First Name: " << this->getFirstName() << '\t';
	cout << "Last Name: " << this->getLastName() << '\t';
	cout << "Age: " << this->getAge() << '\t';
	cout << "daysInCourse: " << this->getDaysToComplete(0) << ", " << this->getDaysToComplete(1) << ", "\
		 << this->getDaysToComplete(2) << endl;
}
