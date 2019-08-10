#pragma once
#include "Student.h"
#include "Degree.h"


class NetworkStudent :
	public Student
{
public:
	NetworkStudent();
	~NetworkStudent();
	Degree getDegreeProgram();
	void print();

private:
	Degree degreeType;
};

