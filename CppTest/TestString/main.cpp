#include "string_utils.h"
#include <string>
using namespace std;


int main(int agrc,char* argv[])
{
	string aaa = "abc";
	string bbb = "1";


	bool result = IsMatchPrefix(aaa,bbb);
	result = IsContainsSubStr(aaa,bbb);

	vector<string> aVec;
	StringSplit("123&","&",aVec,false);


	return 0;
}


/*
class Person
{
public:
	Person(int age):_Age(age)
	{		
	}

	Person(const Person& rhs)
	{
		this->_Age = rhs._Age;
	}

	Person& operator=(const Person& rhs)
	{
		this->_Age = rhs._Age;
		return *this;
	}

public:
	int _Age;
};


int main(int agrc,char* argv[])
{
	Person p1(8);			// ֱ�ӵ��ù��췽��
	Person p2 = 8;			// ֱ�ӵ��ù��췽��������Ҫ��ʱ���󣬵ȼ���Person p1(8)
	Person p3 = Person(8);	// ֱ�ӵ��ù��췽��������ֻ����һ�Σ��ȼ���Person p1(8)

	Person p4 = p1;			// ����copy����
	p4 = p1;				// ����copy��ֵ
	p4 = Person(9);			// �ȵ��ù��췽�����������������ٵ���copy��ֵ
	p4 = 9;					// �ȵ��ù��췽����������ʱ�����ٵ���copy��ֵ

	return 0;
}
*/



/*
int main(int argc, char* argv[])
{
	string aa = "abcd";	
	string bb = aa;
	printf("aa[%x:%s],bb[%x:%s]\n",
		&(aa[0]),
		aa.c_str(),
		&(bb[0]),
		bb.c_str());

	char* pc= (char*)(&aa[1]);
	printf("pc[%x:%c]\n",
		pc,
		*pc);

	*pc = 'h';
	printf("pc[%x:%c]\n",
		pc,
		*pc);

	printf("aa[%x:%s],bb[%x:%s]\n",
		&(aa[0]),
		aa.c_str(),
		&(bb[0]),
		bb.c_str());

	return 0;
}
*/

/*
void setCharPointer(const char* pc)
{
	string ss = "abcde";
	pc = ss.c_str();
}
*/

/*
int main(int argc, char* argv[])
{

	string ss;

	printf("[%s]",ss.c_str());

	char* pc = NULL;

	setCharPointer(pc);


	printf("[%s]",pc);



	string s1 = "aa";
	string s2 = "bb";

	string s3 = s1+"_"+s2;

	char tmp[32] = "abcdef";

	string s4 = tmp;

	s4[3] = 0;

	tmp[2] = '\0';

	string s5 = tmp;
	

	return 0;
}
*/

