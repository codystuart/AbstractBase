#pragma once
class Base
{
private:
	char* _name = nullptr;

public:
	Base(); //default constructor
	Base(const char* name); //overloaded constructor
	
	//rule of 3
	//assignment operator
	Base& operator=(const Base& other);
	//copy constructor
	Base(const Base& other);
	//destructor
	~Base();

	void SetName(const char* name);
	char* GetName(); 
	virtual void DisplayRecord() = 0; //pure virtual function

};

