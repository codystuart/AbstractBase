#include <iostream>
#include "Base.h"

Base::Base()
{

}

Base::Base(const char* name)
{
	SetName(name);
}

Base& Base::operator=(const Base& other)
{
	if (this != &other)
	{
		SetName(other._name);
		
	}

	return *this;
}


Base::Base(const Base& other)
{
	*this = other;

}

Base::~Base()
{
	delete[] _name;
}

void Base::SetName(const char* name)
{
	//remove pre-existing array
	if (_name != nullptr)
	{
		delete[] _name;
	}
	// get the size of new char array
	int len = strlen(name) + 1;
	//create new char array
	_name = new char[len];
	//copy char from passed in name to member field _name
	strcpy_s(_name, len, name);
}

char* Base::GetName()
{
	return _name;
}
