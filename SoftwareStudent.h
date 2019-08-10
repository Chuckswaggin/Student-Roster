#pragma once
#include "Student.h"
#include "Degree.h"
class SoftwareStudent :
	public Student
{
public:
	SoftwareStudent();		// Default constructor
	~SoftwareStudent();		// Destructor
	Degree getDegreeProgram();	// Returns degreeType
	void print();			// Prints the SoftwareStudent's information

private:
	Degree degreeType;
};

