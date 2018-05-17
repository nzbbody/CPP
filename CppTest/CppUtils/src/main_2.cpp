#include "CppUtils.h"
#include <time.h>
#include <iostream>
#include <wtypes.h>

using namespace std;


class Student
{
public:
	Student(string name):_Name(name)
	{
	}
	void SayHello()
	{
		printf("Hello,I am %s",_Name.c_str());
	}
public:
	string _Name;
};

typedef int (*FunPtr)(int a,int userHandle);

int StudentCallBack(int a,int userHandle)
{
	Student* pStu = (Student*)userHandle;
	pStu->SayHello();
	return a+1;
}

class Dog
{
public:
	Dog(string name):_Name(name)
	{
		printf("I am a dog[%s]\n",_Name.c_str());
	}

public:
	string _Name;
};

class Person
{
public:
	Person(Dog dog):_Dog(dog)
	{
		printf("I have a dog[%s]\n",_Dog._Name.c_str());
	}

public:
	Dog _Dog;
};

/*
int main(int argc, char* argv[])
{
	string dogName = "Hali";
	// ��ߵ�p1֮ǰ�����ڣ�Ҫ���ù��췽������һ������
	// ���췽���Ĳ�����������Dog���󣬵����ұ���һ��string�������Բ�ƥ�䡣
	// ��ˣ���Ҫһ��������̣��м����һ����ʱ�������£�
	// dogName --> ��ʱ��Dog���� -->p1
	Person p1 = dogName;

	// ����Ϊʲô����ʧ�ܣ�
	// ������̣��Ǳ��������еģ������м�ֻ������һ�Σ�Ϊʲô��
	// ������������Σ���ô�����Ҫ�ҵ����п��ܵ�����·������������������
	// ���ܻ����ѭ�����䣬���Ҵ�����������·����·������Ҳһ����ѡ����һ���أ�
	//Person p2 = "Hali";


	Dog hali = "Hali";
	p1 = hali;
}
*/


//int main(int argc, char* argv[])
//{
//	Student a("Andy");
//
//	FunPtr fun = StudentCallBack;
//	int hh = fun(3,(int)&a);
//}
//
//int Fool(int a,int userHanlde)
//{
//	return a+1;
//}

/*
int main(int argc, char* argv[])
{
	FunPtr fun = Fool;
	int hh = fun(3,0);

	Student a("Andy");
	SayHelloPtr sayHello = &Student::SayHello;
	(a.*sayHello)();

	int gg =0;
}
*/



/*
int main(int argc, char* argv[])
{
	time_t aa = time(NULL);

	time_t bb;
	time(&bb);
 
	time_t cc;
	time_t dd = time(&cc);


	SYSTEMTIME sysTime;
	GetLocalTime(&sysTime);
	sysTime.wYear = 2015;
	sysTime.wMonth = 10;
	sysTime.wDay = 20;

	sysTime.wHour = 14;
	sysTime.wMinute = 38;
	sysTime.wSecond = 30;

	int ret = SetLocalTime(&sysTime);
	int errCode = GetLastError();

	return 0;
}
*/