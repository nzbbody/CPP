
#include "student.h"
#include <iostream>

Student a;

void DoSthAtExit()
{
	int gg =0;
}

int main(int argc, char* argv[])
{
	Student s1(8);
	Student s2(6);

	bool b = s1.IsAgeBig(s2);




	//Student a;
	//a.Say();

	//getchar();
	
	//atexit(DoSthAtExit); // 注册，在main结束之后调用，在全局对象析构之前调用
	//exit(0); //这个调用不是必要的，加在return之前，导致return不执行
	return 0;	
}

