#pragma once
#include "Base.h"

//publicly derived from Base class
class Student: public Base
{

private:
	float _gpa;

public:
	Student(); //default constructor
	virtual ~Student(); //destructor

	void SetGpa(float gpa);
	void DisplayRecord();
};

