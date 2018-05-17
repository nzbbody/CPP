#include "student.h"

Student::Student():_Age(0),_Name("")
{

}

Student::Student(int age, const string& name):_Age(age),_Name(name)
{

}

bool Student::operator==(const Student& rhs)
{
	return (_Age == rhs._Age && _Name == rhs._Name);
}