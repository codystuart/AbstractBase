// StuartCodyAbstractBase.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include "Base.h"
#include "Employee.h"
#include "Student.h"

int ValidateInt(int number);
float ValidateFloat(float number);
std::vector<Base*>& AddRecord(std::vector<Base*>& v);
void DisplayRecords(std::vector<Base*>& v);
void DuplicateRecord(std::vector<Base*>& v);


int main()
{
	// include memory leak detection
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	_CrtSetBreakAlloc(-1); // set block of memory to find memory leak
	_CrtDumpMemoryLeaks();

	//declare a vector or type Base pointers to store our upcasted employees and students
	std::vector<Base*> v;

	//create a bool so our while loop has a condition to check to run again
	bool runAgain = true;
	while (runAgain)
	{
		system("cls");
		std::cout << "1.Add a record\n2.Display all records\n3.Duplicate a record\n4.Exit\nWhat would you like to do?" << std::endl;
		//initialize an integer to store a value for our menu options to use in the switch/case statement
		int menuChoice = 0;
		//confirm the user enters a valid integer and assign it to menuChoice if valid
		menuChoice = ValidateInt(menuChoice);
		//make the user choose again if menuChoice is not a 1,2,3, or 4
		if (menuChoice > 4 || menuChoice < 1)
		{
			std::cout << "Invalid Selection" << std::endl;
			std::cout << "1.Add a record\n2.Display all records\n3.Duplicate a record\n4.Exit\nWhat would you like to do?" << std::endl;
			menuChoice = ValidateInt(menuChoice);
		}
		switch (menuChoice)
		{
		case 1:
			AddRecord(v);//,emp,stud);
			break;
		case 2:
			DisplayRecords(v);
			system("pause");
			break;
		case 3:
			DuplicateRecord(v);
			system("pause");
			break;
		case 4:
			std::cout << "Exiting..." << std::endl;
			runAgain = false;

			break;
		}
	}

	for (int i = 0; i < v.size(); i++)
	{
		delete v[i];
	}

}

std::vector<Base*>& AddRecord(std::vector<Base*>& v)
{
	system("cls");
	//initialize variables needed for case statement
	char name[32];
	int salary = 0;
	float gpa = 0;

	std::cout << "1.Employee\n2.Student\nPlease select a record type" << std::endl;
	int recordType = 0;
	recordType = ValidateInt(recordType);
	switch (recordType)
	{
	case 1:
		std::cout << "\nPlease enter the employees name" << std::endl;
		std::cin.clear();
		std::cin.ignore(INT_MAX, '\n');
		std::cin.getline(name, 32);
		std::cout << "\nPlease enter " << name << "'s salary" << std::endl;
		salary = ValidateInt(salary);
		if (salary < 0)
		{
			std::cout << "Salary can't be negative" << std::endl;
			salary = ValidateInt(salary);
		}
		v.push_back(new Employee(name, salary));
		std::cout << "\nAdded record for " << name << " with a salary of " << salary << std::endl;
		break;

	case 2:
		std::cout << "\nPlease enter the students name" << std::endl;
		std::cin.clear();
		std::cin.ignore(INT_MAX, '\n');
		std::cin.getline(name, 32);
		std::cout << "\nPlease enter " << name << "'s GPA" << std::endl;
		gpa = ValidateFloat(gpa);
		v.push_back(new Student(name, gpa));
		std::cout << "\nAdded record for " << name << " with a gpa of " << gpa << std::endl;
		break;
	}
	system("pause");
	return v;
}

void DisplayRecords(std::vector<Base*>& v)
{
	system("cls");
	std::cout << "Now Dispalying " << v.size() << " record(s)" << std::endl;
	std::cout << "------------------------" << std::endl;


	for (int i = 0; i < v.size(); i++)
	{
		
		std::cout << "Record #" << i+1 << std::endl;
		v[i]->DisplayRecord();
		std::cout << std::endl;
	}
}

void DuplicateRecord(std::vector<Base*>& v)
{
	std::cout << "Which record would you like to duplicate?" << std::endl;
	for (int i = 0; i < v.size(); i++)
	{

		std::cout << "Record #" << i << std::endl;
		v[i]->DisplayRecord();
		std::cout << std::endl;
	}
	std::cout << "Select record# ";
	int recordNum = 0;
	recordNum = ValidateInt(recordNum);
	Employee* empTest = dynamic_cast<Employee*>(v[recordNum]);
	if (empTest != nullptr)
	{
		Employee* empCopy = new Employee(*empTest);
		v.push_back(empCopy);
	}
	else
	{
		Student* studTest = dynamic_cast<Student*>(v[recordNum]);
		if (studTest != nullptr)
		{
			Student* studCopy = new Student(*studTest);
			v.push_back(studCopy);
		}
	}

	std::cout << "Record added!" << std::endl;
}

int ValidateInt(int number)
{
	while (true)
	{
		if (std::cin >> number)
		{
			break;
		}
		std::cin.clear();
		std::cin.ignore(INT_MAX, '\n');
		std::cout << "Selection Invalid" << std::endl;
	}
	return number;
}


float ValidateFloat(float number)
{
	while (true)
	{
		if (std::cin >> number)
		{
			break;
		}
		std::cin.clear();
		std::cin.ignore(INT_MAX, '\n');
		std::cout << "Selection Invalid" << std::endl;
	}
	return number;
}
