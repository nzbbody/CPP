#ifndef PERSON_H_
#define PERSON_H_

#include "dog.h"

class Dog;

class Person
{
public:
	Person();
	~Person();

public:
	Dog _Dog;
};

#endif