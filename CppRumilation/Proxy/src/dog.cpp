#include "dog.h"

void Dog::Eat()
{
	this->Animal::Eat();
	printf("I eat meat\n");
}

Animal* Dog::Clone() const
{
	return new Dog(this->_height);
}

Dog::Dog(int height):_height(height)
{

}