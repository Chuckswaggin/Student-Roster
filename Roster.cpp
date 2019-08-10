#include "Roster.h"
#include <string>
#include <iostream>
#include <sstream>
using namespace std;

// Default constructor
Roster::Roster()
{
}

// Desctructor
Roster::~Roster()
{
	// Loop through entire array of pointers
	for (int i = 0; i < 5; ++i) {
		// Check if the current pointer is already nullptr
		if (classRosterArray[i] != nullptr) {
			// If not nullptr, set it to nullptr
			classRosterArray[i] = nullptr;
		}
	}
}

// Return Student pointer at index i
Student* Roster::getRosterElement(int i) {
	return classRosterArray[i];
}

// Add Student to Roster
void Roster::add(string studentID, string firstName, string lastName, string emailAddress, \
	             int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, \
	             Degree degType, int location) {
	// Check the degreeType and create appropriate Student object
	if (degType == SECURITY) {
		classRosterArray[location] = new SecurityStudent;
	}
	else if (degType == NETWORKING) {
		classRosterArray[location] = new NetworkStudent;
	}
	else {
		classRosterArray[location] = new SoftwareStudent;
	}
	// Set the values of the newly created Student
	classRosterArray[location]->setStudentID(studentID);
	classRosterArray[location]->setFirstName(firstName);
	classRosterArray[location]->setLastName(lastName);
	classRosterArray[location]->setEmailAddress(emailAddress);
	classRosterArray[location]->setAge(age);
	classRosterArray[location]->setDaysToComplete(daysInCourse1, daysInCourse2, daysInCourse3);
}

// Remove Student with studentID from Roster
void Roster::remove(string studentID) {
	bool found = false;
	int i = 0;	// index variable
	while (!found && i < 5) {
		// Check if current pointer is nullptr
		if (classRosterArray[i] != nullptr) {
			// If not, check if studentID matches
			if (classRosterArray[i]->getStudentID() == studentID) {
				// If it matches, delete by setting to nullptr
				classRosterArray[i] = nullptr;
				found = true;	// Exit the loop
			}
		}
		++i;
	}
	// If no Student with studentID exists, print that it was not found
	if (!found) {
		cout << "Student not found." << endl;
	}
}

// Print the information for all Students in Roster
void Roster::printAll() {
	for (int i = 0; i<5; ++i) {
		classRosterArray[i]->print();
	}
	cout << endl;
}

// Calculate and print the average number of days left in courses for Student with studentID
void Roster::printAverageDaysInCourse(string studentID) {
	int i = 0;
	// Loop through array until Student is found
	while (classRosterArray[i]->getStudentID() != studentID && i < 5) {
		++i;
	}
	
	// Calculate the average number of days left in courses
	int sum = 0;
	for (int j = 0; j<3; ++j) {
		sum += classRosterArray[i]->getDaysToComplete(j);
	}
	cout << sum / 3 << endl;
}

// Find and print all invalid email addresses in Roster
void Roster::printInvalidEmails() {
	cout << "Invalid emails:" << endl;
	for (int i = 0; i<5; ++i) {	// Loop through entire array
		if (classRosterArray[i]->getEmailAddress().find('@') == string::npos || \
			classRosterArray[i]->getEmailAddress().find('.') == string::npos || \
			classRosterArray[i]->getEmailAddress().find(' ') != string::npos) {
			cout << classRosterArray[i]->getEmailAddress() << endl;
	}
	}
	cout << endl;
}

// Print all Student information for Students with degreeType degreeProgram
void Roster::printByDegreeProgram(int degreeProgram) {
	for (int i = 0; i<5; ++i) {
		if (classRosterArray[i]->getDegreeProgram() == degreeProgram) {
			classRosterArray[i]->print();
		}
	}
	cout << endl;
}

// Main function
int main() {
	// Print course information
	cout << "Course title: - Scripting and Programming: Applications" << endl;
	cout << "Programming language: C++" << endl;

	// Create strings with the Student information
	const string Students[] = \
	{"A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY", \
	 "A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK", \
	 "A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE", \
	 "A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY", \
	 "A5,John,Smith,nmoo104@wgu.edu,24,10,20,30,SOFTWARE"};
	 
	string info[9];		// Array to hold parsed Student information
	Roster classRoster;	// Class Roster

	for (int i = 0; i<5; ++i) {
		// Put current string into a stringstream
		stringstream ss(Students[i]);
		// Parse the string, comma is the separator
		for (int j = 0; j<9; ++j) {
			getline(ss, info[j], ',');
		}
		
		// Check degreeType and add correct Student type to Roster
		if (info[8] == "SECURITY") {
			classRoster.add(info[0], info[1], info[2], info[3], stoi(info[4]), stoi(info[5]), \
				stoi(info[6]), stoi(info[7]), SECURITY, i);
		}
		else if (info[8] == "NETWORK") {
			classRoster.add(info[0], info[1], info[2], info[3], stoi(info[4]), stoi(info[5]), \
				stoi(info[6]), stoi(info[7]), NETWORKING, i);
		}
		else {
			classRoster.add(info[0], info[1], info[2], info[3], stoi(info[4]), stoi(info[5]), \
				stoi(info[6]), stoi(info[7]), SOFTWARE, i);
		}
	}

	// Print all Student information
	classRoster.printAll();
	// Print the invalid emails
	classRoster.printInvalidEmails();
	// Print the average number of days left in courses for all Students
	for (int i = 0; i<5; ++i) {
		cout << "Average days in course for student " << classRoster.getRosterElement(i)->getStudentID() << ": ";
		classRoster.printAverageDaysInCourse(classRoster.getRosterElement(i)->getStudentID());
	}
	cout << endl;

	// Print information for all SoftwareStudents
	classRoster.printByDegreeProgram(SOFTWARE);
	// Remove Student with studentID A3
	classRoster.remove("A3");
	// Try to remove the Student with studentID A3 again, should print that it's not found
	classRoster.remove("A3");

	// De-allocate classRoster memory
	classRoster.~Roster();

	return 0;
}
