#ifndef ANIMAL_PROXY_H_
#define ANIMAL_PROXY_H_

#include "animal.h"

class AnimalProxy
{
public:
	AnimalProxy();
	~AnimalProxy();
	AnimalProxy(const AnimalProxy& rhs);
	AnimalProxy& operator=(const AnimalProxy& rhs);

	AnimalProxy(const Animal& animal);

	void Eat();

private:
	Animal* _pa;
};

#endif