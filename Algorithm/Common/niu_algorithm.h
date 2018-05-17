#ifndef NIU_ALGORITHM_H_
#define NIU_ALGORITHM_H_

#include <string>
#include <vector>

using namespace std;

enum OptType
{
	Opt_Add = 0,
	Opt_Del,
	Opt_Mod,	
};


struct Student
{
	int		_Opt;
	int		_Id;
	string _Name;

	Student(int id,string name):_Id(id),_Name(name)
	{

	}


	bool operator==(const Student& rhs)
	{
		if(_Id == rhs._Id)
		{
			return true;
		}

		return false;
	}
};



class NiuAlgorithm
{
public:
	static void GetOptVec(vector<Student>& oldVec,vector<Student>& newVec,vector<Student>& optVec);


};

#endif