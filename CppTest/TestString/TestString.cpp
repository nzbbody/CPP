// TestString.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <string>

using namespace std;

void setCharPointer(const char* pc)
{
	string ss = "abcde";
	pc = ss.c_str();
}


int _tmain(int argc, _TCHAR* argv[])
{

	string ss;

	printf("[%s]",ss.c_str());

	char* pc = NULL;

	setCharPointer(pc);


	printf("[%s]",pc);



	string s1 = "aa";
	string s2 = "bb";

	string s3 = s1+"_"+s2;

	char tmp[32] = "abcdef";

	string s4 = tmp;

	s4[3] = 0;

	tmp[2] = '\0';

	string s5 = tmp;
	

	return 0;
}

