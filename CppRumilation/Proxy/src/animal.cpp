#include "animal.h"

Animal::Animal():_name(""),_age(0)
{

}

Animal::Animal(string name,int age):_name(name),_age(age)
{

}

Animal::~Animal()
{

}

void Animal::Say()
{
	printf("I am an animal\n");
}

void Animal::Eat()
{
	printf("I donot know eat what\n");
}


Animal* Animal::Clone() const
{
	//return NULL;
	return new Animal();
}