
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
	
	//atexit(DoSthAtExit); // ע�ᣬ��main����֮����ã���ȫ�ֶ�������֮ǰ����
	//exit(0); //������ò��Ǳ�Ҫ�ģ�����return֮ǰ������return��ִ��
	return 0;	
}

