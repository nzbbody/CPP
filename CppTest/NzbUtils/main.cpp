#include <string>
#include <vector>
#include <map>
#include "nzb_utils.h"
using namespace std;

#include <stdio.h>


struct Person
{
public:
	int		_Age;
	string	_Name;

	bool operator==(const Person& rhs)
	{
		return (this->_Age == rhs._Age && this->_Name == rhs._Name);
	}

};




int main()
{
	map<int,vector<string> > aMap;

	vector<string> aVec;
	aVec.push_back("Andy");
	aVec.push_back("Bill");

	aMap[1] = aVec;

	aVec.erase(--aVec.end());
	aMap[2] = aVec;

	aVec.push_back("Caroline");
	aVec.push_back("David");
	aMap[3] = aVec;

	vector<string>::iterator iter = min(aVec.begin(),aVec.end());


	int hh =0;
}


/*
class Person
{
public:
	Person()
	{
		_Age = 0;
	}
	void Destroy()
	{
		delete this;
	}

private:
	~Person()
	{
		Person bb;
		bb.~Person();
	}

public:
	int	   _Age;
};
*/

/*
int main()
{
	string result = "20161125163846";
	result.insert(8,1,'T');
	result.insert(15,1,'Z');

	//Person aa; // 报错 无法访问 private 成员
	//Person* pa = new Person();
	////delete pa; // 报错 无法访问 private 成员
	//pa->Destroy();
	return 0;
}
*/


/*
class Person
{
public:
	int	   _Age;
	string _Name;
};

int main()
{
	Person* p = new Person();
	p->_Age = 18;
	p->_Name = "Andy";
	
	delete p;
	p = NULL;
	p->_Age = 20;
	p->_Name = "Bill";

	return 0;
}
*/


/*
int main()
{
	string aa;
	int d = sizeof(aa);
	string* ps = &aa;

	// 使用内存窗口，观察ps
	aa = "123456781234567";  // 16个字节（包含\0），分配至string本身上
	aa = "1234567812345678"; // 17个字节（包含\0），分配其他内存，里面有个指针关联
	return 0;
}
*/


//int main()
//{
//	const int a =10;
//	int* pa = const_cast<int*>(&a);
//
//	*pa=20;
//	
//	return 0;
//}


//struct Dog
//{
//	int		_Id;
//	int		_Age;
//	int		_Length;
//	char	_Desc[1];		//包含描述 16个字节
//};
//
//int main(int argc,char* argv[])
//{
//	char* pc = new char[28];
//	memset(pc, 0,28);
//
//	Dog* d = (Dog*)pc;
//	d->_Id = 1;
//	d->_Age = 2;
//	d->_Length = 28;
//
//	sprintf(d->_Desc,"%s",
//		"abcdefg");
//
//	return 0;
//}

/*
struct Person
{
public:
	int _Age;

	Person(int age)
	{
		_Age = age;
	}
};

class PersonCompare
{
public:
	bool operator()(const Person& lhs,const Person& rhs)
	{
		return lhs._Age > rhs._Age;
	}
};



int main(int argc,char* argv[])
{
	Person p1(1);	
	Person p2(2);
	Person p3(3);

	vector<Person> pVec;
	pVec.push_back(p1);
	pVec.push_back(p2);
	pVec.push_back(p3);
	pVec.insert(pVec.begin(),p3);


	//sort(pVec.begin(),pVec.end(),PersonCompare());

	//for(vector<Person>::iterator iter = pVec.begin();
	//	iter != pVec.end(); ++iter)
	//{
	//	printf("%d\n",iter->_Age);
	//}

	return 0;
}
*/


/*
int main(int argc,char* argv[])
{
	//char workDir[64] = {0};
	//getcwd(workDir,64);

	//printf("工作目录为：%s",workDir);

	//int aa = 17;
	//printf("aa[0x%x]",
	//	aa);

	//int now = time(NULL);
	int now = 1473142696;
	string timeStr = NzbUtils::GetTimeStr(now);

	timeStr = "2016-09-06 14:18:16";
	now = NzbUtils::GetUnixTimeStamp(timeStr);

	//Person p1(4);	
	//Person p2(2);
	//Person p3(100);
	//Person p4(9);

	//vector<Person> pVec;
	//pVec.push_back(p1);
	//pVec.push_back(p2);
	//pVec.push_back(p3);
	//pVec.push_back(p4);

	//sort(pVec.begin(),pVec.end());


	getchar();
	return 0;
}
*/

/*
struct AAA
{
	char	_A1;
	short	_A2;
	int		_A3;
	double	_A4;
	int     _A5;
};


int main(int argc,char* argv[])
{
	AAA a;
	a._A1 = 65;
	a._A2 = 18;
	a._A3 = 0xffffffff;
	a._A4 = 88;
	a._A5 = 17;

	AAA b;
	b._A1 = 65;
	b._A2 = 18;
	b._A3 = 0xffffffff;
	b._A4 = 88;
	b._A5 = 17;

	if(a == b)
	{
		int hh = 0;
	}


	printf("[%d:%d:%u:%lf:%d]",
		a._A1, a._A2, a._A3, a._A4, a._A5);

	getchar();
	return 0;
}
*/

/*
class AAA
{
public:
	AAA():_A1(0),_A2(0),_A3(0)
	{
	
	}

	AAA(int a3):AAA()
	{
		_A3 = a3;
	}
public:
	int _A1;
	int _A2;
	int _A3;
};


int main()
{
	AAA a1;
	AAA a2(9);

	return 0;
}
*/

/*
int Sum(int a,int b)
{
	return a+b;
}

struct AAA
{
	char	_A1;
	short	_A2;
	int		_A3;
	double	_A4;
};

int main()
{
	AAA* pa = new AAA();
	pa->_A1 = 100;

	int a = pa->_A1;
	delete pa;

	pa->_A1 = 17;
	int b = pa->_A1;

	return 0;
}
*/


