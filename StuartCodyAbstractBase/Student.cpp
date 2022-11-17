#include <iostream>
#include "Student.h"

Student::Student() : _gpa(0)
{

}

Student::Student(const char* name, float gpa)
{
	SetName(name);
	SetGpa(gpa);
}

Student::~Student()
{

}

void Student::SetGpa(float gpa)
{
	_gpa = gpa;
}

void Student::DisplayRecord()
{
	std::cout << "Name: " << GetName() << std::endl;
	std::cout << "GPA: " << _gpa << std::endl;
}
