#ifndef DOG_H_
#define DOG_H_
#include "Animal.h"

class Dog : public Animal
{
public:
	virtual void Copy(Animal* animal);
	
	virtual void Say(int a);

	virtual void Play();

	void aaa();


public:
	int _Height;
};

#endif