#include <stdio.h>
#include <string>
#include <vector>
#include <list>
using namespace std;

/*
int main()
{
	list<int> aContainer;
	aContainer.push_back(1);
	aContainer.push_back(2);
	aContainer.push_back(3);

	list<int>::iterator iter = aContainer.begin();
	int* pp = &*iter;
	int aa = *iter;
	printf("Int addr[%p] value[%d]\n",
		pp,
		aa);

	aContainer.erase(iter);

	pp = &*iter;
	aa = *iter;
	printf("Int addr[%p] value[%d]\n",
		pp,
		aa);

	getchar();
	return 0;
}
*/

struct Person
{
	int     _Age;
	string  _Name;

	Person()
	{

	}

	Person(int age,string name)
	{
		_Age = age;
		_Name = name;   
	}
	
	

	Person(const Person& p)
	{
		_Age = p._Age;
		_Name = p._Name;
	}

};


int main()
{
	list<Person> aContainer;
	aContainer.push_back(Person(1,"Andy"));
	aContainer.push_back(Person(2,"Bill"));
	aContainer.push_back(Person(3,"Caroline"));

	list<Person>::iterator iter = aContainer.begin();
	Person* pp = &*iter;
	Person aa = *iter;
	printf("Person addr[%p] value[%d:%s]\n",
		pp,
		aa._Age,
		aa._Name.c_str());

	aContainer.erase(iter);

	pp = &*iter;
	aa = *iter;
	printf("Person addr[%p] value[%d:%s]\n",
		pp,
		aa._Age,
		aa._Name.c_str());

	getchar();
	return 0;
}





/*
int main()
{
	vector<int> aVec;
	aVec.push_back(1);
	aVec.push_back(2);
	aVec.push_back(3);

	vector<int> bVec;
	vector<int> cVec;
	bVec = aVec;
	bVec = cVec;


	return 0;
}
*/


/*
int main()
{
	map<int,string> aMap;
	aMap[1] = "Andy";
	aMap[2] = "Bill";
	aMap[3] = "Caroline";

	map<int,string>::iterator iter = aMap.begin();
	aMap.erase(1);

	if(iter == aMap.end())
	{
		
	}
	//int aa = iter->first;
	return 0;
}
*/

/*
struct Person
{
	int     _Age;
	string  _Name;

	Person()
	{
 
	}

	Person(int age,string name)
	{
		_Age = age;
		_Name = name;   
	}

	Person(const Person& p)
	{
		_Age = p._Age;
		_Name = p._Name;
	}

};
*/

/*
class Add
{
public:
	Add(int delta):_Delta(delta)
	{

	}

	int operator() (int a)
	{
		return a+_Delta;
	}

public:
	int _Delta;
};
*/


/*
int main()
{
	list<int> aList;
	aList.push_back(1);
	aList.push_back(2);

	int a = 1;

	list<int>::iterator iter= find(aList.begin(),aList.end(),a);

	if(iter == aList.end())
	{
		aList.push_back(a);
	}

	while(aList.size() >1)
	{
		int b = aList.front();
		aList.pop_front();
	}

	return 0;
}
*/



/*
int main()
{
	Person p1(1,"Andy");
	Person p2(2,"Bill");
	Person p3(3,"Caroline");

	//Person p1;
	//Person p2;
	//Person p3;

	map<int,Person> aVec;
	aVec[1] = p1;
	aVec[2] = p2;
	aVec[3] = p3;


	return 0;
}
*/

/*
class FindAnimal
{
public:
	FindAnimal(int id):_id(id)
	{

	}


	bool operator()(const Animal& a)
	{
		if(a._Age>_id)
		{
			return true;
		}
		
		return false;
	}

private:
	int _id;
};

int main(int argc, char* argv[])
{
	map<int,string> aMap;
	aMap[1]= "Andy";
	aMap[2]= "Bill";
	aMap[3]= "Andy";

	aMap.erase(1);

	map<int,string>::iterator iter = aMap.begin();
	aMap.erase(iter);


	getchar();
	return 0;
}
*/








/*
int main(int argc, char* argv[])
{
	//int intArray[] = {4,3,8,5,6,7};

	//vector<int> intVec(intArray,intArray+sizeof(intArray)/sizeof(int));

	//vector<int>::iterator iter1= find(intVec.begin(),intVec.end(),5);

	//vector<int>::iterator iter1= find_if(intVec.begin(),intVec.end(),5);


	//map<int,int> intMap;
	//map<int,int>::iterator iter2 = intMap.find(5);


	Animal a1(1,"Andy");
	Animal a2(2,"Bill");
	Animal a3(3,"Caroline");
	Animal a4(4,"David");
	Animal a5(5,"Eric");


	vector<Animal> anVec;
	anVec.push_back(a1);
	anVec.push_back(a2);
	anVec.push_back(a3);
	anVec.push_back(a4);
	anVec.push_back(a5);

	vector<Animal>::iterator iter1= find(anVec.begin(),anVec.end(),a3);

	vector<Animal>::iterator iter2= find_if(anVec.begin(),anVec.end(),FindAnimal(4));



	getchar();
	return 0;
}
*/





/*
int main(int argc, char* argv[])
{
	vector<int> intVec;
	intVec.push_back(1);
	intVec.push_back(2);
	intVec.push_back(3);
	intVec.push_back(4);

	for(vector<int>::iterator iter = intVec.begin(); iter != intVec.end();)
	{
		if(*iter > 2)
		{
			intVec.erase(iter++);
		}
		else
		{
			++iter;
		}
	}

	getchar();
	return 0;
}
*/

/*
int main(int argc, char* argv[])
{
	map<int,string> intStrMap;
	intStrMap[1] = "Andy";
	intStrMap[2] = "Bill";
	intStrMap[3] = "Caroline";
	intStrMap[4] = "David";

	for(map<int,string>::iterator iter = intStrMap.begin(); iter != intStrMap.end();)
	{
		if(iter->first > 2)
		{
			intStrMap.erase(iter++);
		}
		else
		{
			++iter;
		}
	}

	getchar();
	return 0;
}
*/
