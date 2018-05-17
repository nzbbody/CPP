#ifndef DOG_H_
#define DOG_H_

#include "animal.h"

class Dog : public Animal
{
public:
	Dog(int height);

	virtual void Eat();

	virtual Animal* Clone() const;

private:
	int  _height;
};

#endif