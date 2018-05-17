// Test100.cpp : Defines the entry point for the console application.

#include "Animal.h"
#include "Dog.h"
#include "YellowDog.h"
#include "Trace.h"
#include <string>
#include <map>


void TestTrace()
{
	// Trace trace;
	
	// 下面的trace离开作用域，就调用析构方法，它的作用域就是
	for(int i =0; i<5;++i) 
	{
		Trace trace;
	}

	if(9>7)
	{
		Trace trace;
	}
	
	{
		Trace trace;
	}

	int jj =0;
}


// DomCode 标识唯一的设备 
struct DomCode
{
	std::string _DomId;
	std::string _DevCode;

	DomCode()
	{
		_DomId = "";
		_DevCode = "";
	}

	DomCode(std::string domId,std::string devCode):
	_DomId(domId),_DevCode(devCode)
	{
	}

	bool operator <(const DomCode& rhs) const
	{
		if(this->_DomId == rhs._DomId)
		{
			return (this->_DevCode < rhs._DevCode);
		}

		return (this->_DomId < rhs._DomId);
	}
};


struct DeviceExInfo
{
	int					_DevId;
	std::string  		_DevPath;
	std::string  		_OrgPath;
	std::string  		_Name;
	int         		_Status;

	DeviceExInfo()
	{
		_DevId   = 0;
		_DevPath = "";
		_OrgPath = "";
		_Name    = "";
		_Status  = 0;
	}
};


void SetAnimal(Animal*& a)
{
	//a = new Dog;

	//Dog* d = (Dog*) a;
	//
	//d->_Height = 89;


}



/*
	有两个问题，比较奇怪：
	1、子类同名方法会遮掩父类的方法
	2、Debug的时候，虚方法表内只有父类的虚方法
*/
int main(int argc, char* argv[])
{
	Dog d;
	//d.aaa();


	//Animal a = d;
	//a.Animal::Say();

	//int hh = 0;



	//Animal* a = NULL;
	//SetAnimal(a);

	//int dd =9;


	
	//char dst[8] = {0};
	//char* src = new char[4];
	//char* tmp = "abcdfdfggerg";
	//strncpy(src,tmp,8);
	//strncpy(dst,src,7);


	//Dog d;
	//d.Animal::Say();

	//Dog* pDog = new Dog();

	//pDog->Animal::Say();

	//pDog->Play();


	//YellowDog* yeDog = new YellowDog;

	getchar();
	return 0;
}

