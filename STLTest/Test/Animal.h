#ifndef ANIMAL_H_
#define ANIMAL_H_

#include <string>

class Animal
{
//public:
//	bool operator<(const Animal& rhs) const;

public:
	Animal(int age,std::string name):_Age(age),_Name(name)
	{

	}

	bool operator==(const Animal& rhs) const
	{
		if(_Age == rhs._Age && _Name == rhs._Name)
		{
			return true;
		}
		return false;
	}


public:
	int          _Age;
	std::string  _Name;
};

inline bool operator<(const Animal& lhs,const Animal& rhs)
{
	return (lhs._Age < rhs._Age);
}

#endif