#pragma once
#include "Student.h"
#include "Degree.h"


class NetworkStudent :
	public Student
{
public:
	NetworkStudent();		// Default constructor
	~NetworkStudent();		// Destructor
	Degree getDegreeProgram();	// Returns degreeType
	void print();			// Prints the NetworkStudent's information

private:
	Degree degreeType;
};

