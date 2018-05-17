#ifndef ANIMAL_H_
#define ANIMAL_H_

#include <string>

using namespace std;

class Animal
{
public:
	Animal();
	Animal(string name,int age);
	~Animal();
		
	void  Say();

	virtual void Eat();

	virtual Animal* Clone() const;

private:
	string  _name;
	int     _age;
};

#endif