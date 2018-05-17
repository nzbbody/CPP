#include "student.h"
#include <iostream>

Student::Student()
{
	printf("I am a student");
}


Student::Student(int age):_age(age)
{
	printf("I am a student");
}

Student::~Student()
{
	printf("Byebye");
}

void Student::Say()
{
	printf("I am a student\n");
}

bool Student::IsAgeBig(const Student& rhs)
{
	if(this->_age > rhs._age)
	{
		return true;
	}

	return false;
}

bool Tmp::IsAgeBig(const Student& rhs)
{
	if(45 > rhs._age)
	{
		return true;
	}

	return false;
}
