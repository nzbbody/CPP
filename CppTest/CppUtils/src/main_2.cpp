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
	// 左边的p1之前不存在，要调用构造方法创建一个对象。
	// 构造方法的参数期望接收Dog对象，但是右边是一个string对象，明显不匹配。
	// 因此，需要一个适配过程，中间产生一个临时对象。如下：
	// dogName --> 临时的Dog对象 -->p1
	Person p1 = dogName;

	// 下面为什么编译失败？
	// 适配过程，是编译器进行的，但是中间只能适配一次，为什么？
	// 假如可以适配多次，那么编译就要找到所有可能的适配路径，编译器做不到。
	// 可能会存在循环适配，而且存在两条适配路径，路径长度也一样，选择哪一条呢？
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