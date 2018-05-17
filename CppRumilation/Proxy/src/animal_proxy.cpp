#include "animal_proxy.h"

AnimalProxy::AnimalProxy():_pa(NULL)
{

}

AnimalProxy::~AnimalProxy()
{
	delete _pa;
}

// ע�⣺���п��Է����Լ���private��Ա��Ҳ���Է���rhs��private��Ա
AnimalProxy::AnimalProxy(const AnimalProxy& rhs)
{
	_pa = (rhs._pa != NULL ? rhs._pa->Clone():NULL);
}

AnimalProxy& AnimalProxy::operator=(const AnimalProxy& rhs)
{
	if(this != &rhs) // ��ͬ����
	{
		delete _pa; // delete NULL Ҳû������
		_pa = (rhs._pa != NULL ? rhs._pa->Clone():NULL);  // ָ��ΪNULL�ж�
	}
	return *this; // ��������
}

AnimalProxy::AnimalProxy(const Animal& animal):_pa(animal.Clone())
{

}

void AnimalProxy::Eat()
{
	_pa->Eat();
}
