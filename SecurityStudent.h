#pragma once
#include "Student.h"
#include "Degree.h"

class SecurityStudent :
	public Student
{
public:
	SecurityStudent();
	Degree getDegreeProgram();
	void print();
	~SecurityStudent();

private:
	Degree degreeType;
};

