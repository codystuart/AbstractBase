#include <iostream>
#include "Employee.h"


Employee::Employee(): _salary(0)
{

}

Employee::~Employee()
{

}

void Employee::SetSalary(int salary)
{
	_salary = salary;
}

void Employee::DisplayRecord()
{
	std::cout << "Name: " << GetName() << std::endl;
	std::cout << "Salary: " << _salary << std::endl;
}