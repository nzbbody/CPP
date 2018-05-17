#ifndef _PERSONLIB_
#define _PERSONLIB_

#include "DogDll.h"
#include "stdio.h"


class PersonLib
{
public:
	void Say();

private:
	int _age;
	DogDll dog;
};

#endif