#include "Roster.h"
#include <string>
#include <iostream>
#include <sstream>
using namespace std;


Roster::Roster()
{
}


Roster::~Roster()
{
	for (int i = 0; i < 5; ++i) {
		if (classRosterArray[i] != nullptr) {
			classRosterArray[i] = nullptr;
		}
	}
}

Student* Roster::getRosterElement(int i) {
	return classRosterArray[i];
}

void Roster::add(string studentID, string firstName, string lastName, string emailAddress, \
	             int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, \
	             Degree degType, int location) {
	if (degType == SECURITY) {
		classRosterArray[location] = new SecurityStudent;
	}
	else if (degType == NETWORKING) {
		classRosterArray[location] = new NetworkStudent;
	}
	else {
		classRosterArray[location] = new SoftwareStudent;
	}
	classRosterArray[location]->setStudentID(studentID);
	classRosterArray[location]->setFirstName(firstName);
	classRosterArray[location]->setLastName(lastName);
	classRosterArray[location]->setEmailAddress(emailAddress);
	classRosterArray[location]->setAge(age);
	classRosterArray[location]->setDaysToComplete(daysInCourse1, daysInCourse2, daysInCourse3);
}

void Roster::remove(string studentID) {
	bool found = false;
	int i = 0;
	while (!found && i < 5) {
		if (classRosterArray[i] != nullptr) {
			if (classRosterArray[i]->getStudentID() == studentID) {
				classRosterArray[i] = nullptr;
				found = true;
			}
		}
		++i;
	}
	if (!found) {
		cout << "Student not found." << endl;
	}
}

void Roster::printAll() {
	for (int i = 0; i<5; ++i) {
		classRosterArray[i]->print();
	}
	cout << endl;
}

void Roster::printAverageDaysInCourse(string studentID) {
	int i = 0;
	while (classRosterArray[i]->getStudentID() != studentID && i < 5) {
		++i;
	}
	int sum = 0;
	for (int j = 0; j<3; ++j) {
		sum += classRosterArray[i]->getDaysToComplete(j);
	}
	cout << sum / 3 << endl;
}

void Roster::printInvalidEmails() {
	cout << "Invalid emails:" << endl;
	for (int i = 0; i<5; ++i) {
		if (classRosterArray[i]->getEmailAddress().find('@') == string::npos || \
			classRosterArray[i]->getEmailAddress().find('.') == string::npos || \
			classRosterArray[i]->getEmailAddress().find(' ') != string::npos) {
			cout << classRosterArray[i]->getEmailAddress() << endl;
	}
	}
	cout << endl;
}

void Roster::printByDegreeProgram(int degreeProgram) {
	for (int i = 0; i<5; ++i) {
		if (classRosterArray[i]->getDegreeProgram() == degreeProgram) {
			classRosterArray[i]->print();
		}
	}
	cout << endl;
}



int main() {
	cout << "Course title: C867 - Scripting and Programming: Applications" << endl;
	cout << "Programming language: C++" << endl;
	cout << "Student ID: 001103667" << endl;
	cout << "Student name: Nicholas Moore" << endl << endl;

	const string Students[] = \
	{"A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY", \
	 "A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK", \
	 "A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE", \
	 "A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY", \
	 "A5,Nicholas,Moore,nmoo104@wgu.edu,24,10,20,30,SOFTWARE"};
	string info[9];
	Roster classRoster;

	for (int i = 0; i<5; ++i) {
		stringstream ss(Students[i]);
		for (int j = 0; j<9; ++j) {
			getline(ss, info[j], ',');
		}
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

	classRoster.printAll();
	classRoster.printInvalidEmails();
	for (int i = 0; i<5; ++i) {
		cout << "Average days in course for student " << classRoster.getRosterElement(i)->getStudentID() << ": ";
		classRoster.printAverageDaysInCourse(classRoster.getRosterElement(i)->getStudentID());
	}
	cout << endl;

	classRoster.printByDegreeProgram(SOFTWARE);
	classRoster.remove("A3");
	classRoster.remove("A3");

	classRoster.~Roster();

	return 0;
}