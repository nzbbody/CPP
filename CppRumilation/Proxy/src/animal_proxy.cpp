#include "animal_proxy.h"

AnimalProxy::AnimalProxy():_pa(NULL)
{

}

AnimalProxy::~AnimalProxy()
{
	delete _pa;
}

// 注意：类中可以访问自己的private成员，也可以访问rhs的private成员
AnimalProxy::AnimalProxy(const AnimalProxy& rhs)
{
	_pa = (rhs._pa != NULL ? rhs._pa->Clone():NULL);
}

AnimalProxy& AnimalProxy::operator=(const AnimalProxy& rhs)
{
	if(this != &rhs) // 等同测试
	{
		delete _pa; // delete NULL 也没有问题
		_pa = (rhs._pa != NULL ? rhs._pa->Clone():NULL);  // 指针为NULL判断
	}
	return *this; // 返回引用
}

AnimalProxy::AnimalProxy(const Animal& animal):_pa(animal.Clone())
{

}

void AnimalProxy::Eat()
{
	_pa->Eat();
}
