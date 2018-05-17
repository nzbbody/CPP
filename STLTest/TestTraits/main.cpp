// TestTraits.cpp : �������̨Ӧ�ó������ڵ㡣
//
#include <iostream>
#include <string>

using namespace std;

struct BaseType{};
struct CharPoint{};

template <typename T>
struct MyTraits
{
	typedef BaseType value_type;
};

template <>
struct MyTraits<char*>
{
	typedef CharPoint value_type;
};




template <typename T>
T Do_Add(T a,T b,BaseType)
{
	T c = a+b;
	return c;
}

template <typename T>
T Do_Add(T a,T b,CharPoint)
{
	// ������ڰ�ȫ������Ҫ��������ͷ��ڴ�
	T c = new char[strlen(a)+strlen(b)+1];
	memset(c,0,strlen(a)+strlen(b)+1);
	memcpy(c,a,strlen(a));
	memcpy(c+strlen(a),b,strlen(b));

	return c;
}



template <typename T>
T Add(T a,T b)
{
	typename MyTraits<T>::value_type type; 
	return Do_Add(a,b,type);
}





int main(int argc, char* argv[])
{
	int a = 4;
	int b = 7;
	int c = Add(a,b); 


	char* pa = "abc";
	char* pb = "123";
	char* pc = Add(pa,pb); 

	string sa = "hhh";
	string sb = "555";
	string sc = Add(sa,sb); 

	return 0;
}

