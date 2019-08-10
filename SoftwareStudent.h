#pragma once
#include "Student.h"
#include "Degree.h"
class SoftwareStudent :
	public Student
{
public:
	SoftwareStudent();
	~SoftwareStudent();
	Degree getDegreeProgram();
	void print();

private:
	Degree degreeType;
};

