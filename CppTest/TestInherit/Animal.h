#ifndef _ANIMAL_H_
#define _ANIMAL_H_

#include <stdio.h>

class Animal
{
public:
	virtual void Copy(Animal* animal);

	virtual void Say();

	virtual void Say(int a);

public:
	int _Age;
};

#endif