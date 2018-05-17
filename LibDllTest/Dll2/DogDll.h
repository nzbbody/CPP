#ifndef DOGDLL_H_
#define DOGDLL_H_
#include "stdio.h"



#ifdef DLL_FILE
#define DLL_API __declspec(dllexport)
#else
#define DLL_API __declspec(dllimport)
#endif



class DLL_API DogDll
{
public:
	void Say();
};

#endif