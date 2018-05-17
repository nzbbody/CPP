#include "Animal.h"

void Animal::Copy(Animal* animal)
{
	this->_Age = animal->_Age;
}

void Animal::Say()
{
	printf("Animal::I am Say()");
}

void Animal::Say(int a)
{
	printf("Animal::I am Say(int a)");
}