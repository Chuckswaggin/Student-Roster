#pragma once
#include "Student.h"
#include "Degree.h"

class SecurityStudent :
	public Student
{
public:
	SecurityStudent();		// Default constructor
	Degree getDegreeProgram();	// Returns degreeType
	void print();			// Prints the SecurityStudent's information
	~SecurityStudent();		// Destructor

private:
	Degree degreeType;
};

