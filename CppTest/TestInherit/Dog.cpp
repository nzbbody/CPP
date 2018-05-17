#include "Dog.h"

void Dog::Copy(Animal* animal)
{
	Animal::Copy(animal);

	/*Dog* d = (Dog*)animal;
	this->_Height = d->_Height;*/
}

void Dog::Say(int a)
{
	printf("Dog::I am Say(int a)");
}

void Dog::Play()
{
	printf("Dog::I am Play()");
}