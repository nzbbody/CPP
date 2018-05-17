#ifndef _PERSONDLL_
#define _PERSONDLL_

#include "DogLib.h"
#include "stdio.h"

#ifdef DLL_FILE
#define DLL_API __declspec(dllexport)
#else
#define DLL_API __declspec(dllimport)
#endif

class DLL_API PersonDll
{
public:
	void Say();

private:
	int _age;
	DogLib dog;
};

#endif