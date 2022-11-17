#pragma once
#include "Base.h"

//Employee is publicly derived from Base class
class Employee: public Base
{
private:
	int _salary;

public:
	Employee();//default constructor
	Employee(const char* name, int salary);

	virtual ~Employee(); //destructor

	void SetSalary(int salary);
	void DisplayRecord();

};

