#include "CppUtils.h"
#include <time.h>
#include <iostream>
#include <wtypes.h>
#include <map>
#include <string>
#include <list>
#include <algorithm>

using namespace std;

class Cat
{
//public:
//	Cat():_Age(5),_Height(6)
//	{
//
//	}
public:
	int _Age;
	int _Height;
};

class Dog
{
public:
	int _Age;
	int _Height;
};

class Person
{
public:
	Person()
	{

	}
public:
	int _Age;
	int _Height;

	Cat _Cat;
	Dog _Dog;
};



//
//int main(int argc, char* argv[])
//{
//	Person* p1 = new Person;
//	Person* p2 = new Person();
//
//	Person a1;
//	Person a2 = Person();	
//}

/*
int main(int argc, char* argv[])
{
	int i=0;
	vector<char*> pVec;
	while(true)
	{
		printf("num=%d\n",i++);
		//fflush(stdout);
		Sleep(2000);
		char* pc = new char[1024*1024];
		pc = new char[1024*1024];
		memset(pc,0,1024*1024);
		pVec.push_back(pc);
	}
}
*/





map<int,string>::iterator getIterator(map<int,string>& aMap,const string& target)
{
	if(target.size() == 0)
	{
		return aMap.end();		
	}

	for(map<int,string>::iterator iter = aMap.begin();
		iter != aMap.end(); ++iter)
	{
		if(iter->second.find(target,0) != string::npos)
		{
			return iter;
		}
	}
	return aMap.end();
}


void foo(char* a)
{
	a+=1;
}


#pragma pack(push, 1)
struct AAA
{
	char	a1;
	int		a2;
	short	a3;
};
#pragma pack(pop)



int main()
{
	vector<int> aVec;
	aVec.push_back(1);
	aVec.push_back(2);
	aVec.push_back(3);

	vector<int>::iterator iter = aVec.begin();	
	int* pp = &(*iter);
	aVec.erase(iter);

	pp = &(*iter);

	int aa = *iter;

	return 0;
}



/*
int main(int argc, char* argv[])
{
	map<int,string> aMap;
	aMap[1] = "Andy";
	aMap[2] = "Bill";
	aMap[3] = "Caroline";	

	aMap.erase(2);

	return 0;
}
*/



/*
int main(int argc, char* argv[])
{
	list<int> intArray;
	intArray.push_back(1);
	intArray.push_back(2);
	intArray.push_back(3);
	intArray.push_back(2);
	intArray.push_back(4);
	intArray.push_back(5);
	intArray.push_back(2);

	/*
		vectorɾ��Ԫ��
		remove��������ɾ��Ԫ�أ���Ϊ��
			Ҫɾ��Ԫ�أ�����֪������һ�����������������ĳ�Ա����ɾ��Ԫ�ء�
			����removeֻ����һ�Ե���������֪������һ��������
		remove���������ǣ�
			һ��ѹ������ɾ����ֵ�ڵ������汣����ֵ��������������֮��ɾ����ֵ���ܲ������䡣
			remove�����µ��߼��յ㡣
	*/
	//intArray.erase(remove(intArray.begin(),intArray.end(),2),intArray.end());
//	intArray.remove(2);
//
//	return 0;
//}



/*
int main(int argc, char* argv[])
{
	vector<int> intArray;
	intArray.push_back(1);
	intArray.push_back(2);
	intArray.push_back(3);
	intArray.push_back(4);
	intArray.push_back(3);

	intArray.remove(3);

	int kk = 0;

	for(list<int>::iterator iter = intVec.begin(); iter != intVec.end();)
	{
		if(*iter%2 == 0)
		{
			//iter = intVec.erase(iter);
			intVec.erase(iter++);
		}
		else
		{
			++iter;
		}
	}

	for(list<int>::iterator iter = intVec.begin(); iter != intVec.end(); ++iter)
	{
		printf("%d\n",*iter);
	}

	getchar();

	return 0;
}
*/







