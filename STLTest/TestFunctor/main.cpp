// TestFunctor.cpp : 定义控制台应用程序的入口点。
//
#include "student.h"
#include <vector>
#include <algorithm>
#include <functional>

class Finder:public unary_function<Student,bool>
{
public:
	Finder(const Student& stu):_stu(stu)
	{

	}

	bool operator()(const Student& rhs) const
	{
		if(rhs._Age>_stu._Age)
		{
			return true;
		}
		return false;
	}

private:
	Student _stu;
};

struct Student_Age_Greater:public binary_function<Student, Student, bool>
{
	bool operator()(const Student& lhs,const Student& rhs) const
	{
		return (lhs._Age > rhs._Age);
	}
};

bool operator>(const Student& lhs,const Student& rhs)
{
	return lhs._Age > rhs._Age;
}


template <>
struct greater<Student>: public binary_function<Student, Student, bool>
{
	bool operator()(const Student& _Left, const Student& _Right) const
	{
		return (_Left._Age > _Right._Age);
	}
};

//struct StudentNameCompare: public binary_function<Student, Student, bool>
//{
//	bool operator()(const Student& _Left, const Student& _Right) const
//	{
//		return (_Left._Age > _Right._Age);
//	}
//};

template <typename T>
struct StudentNameCompare: public binary_function<T, T, bool>
{
	bool operator()(const T& _Left, const T& _Right) const
	{
		return (_Left._Age > _Right._Age);
	}
};



int main(int argc, char* argv[])
{
	Student s1(20,"Andy");
	Student s2(23,"Bill");
	Student s3(28,"Caroline");
	Student s4(27,"David");
	Student s5(21,"Eric");

	vector<Student> stuVec;
	stuVec.push_back(s1);
	stuVec.push_back(s2);
	stuVec.push_back(s3);
	stuVec.push_back(s4);
	stuVec.push_back(s5);

	Student target(27,"David");

	vector<Student>::iterator iter = find(stuVec.begin(),stuVec.end(),target);
	iter = find_if(stuVec.begin(),stuVec.end(),Finder(target));
	iter = find_if(stuVec.begin(),stuVec.end(),not1(Finder(target)));
	iter = find_if(stuVec.begin(),stuVec.end(),bind2nd(greater<Student>(),target));	
	iter = find_if(stuVec.begin(),stuVec.end(),bind2nd(StudentNameCompare<Student>(),target));
	iter = find_if(stuVec.begin(),stuVec.end(),not1(bind2nd(StudentNameCompare<Student>(),target)));


	getchar();

	return 0;
}
