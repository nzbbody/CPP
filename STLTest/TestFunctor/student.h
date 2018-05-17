#ifndef STUDENT_H_
#define STUDENT_H_

#include <string> 

using namespace std;

class Student
{
public:
	Student();

	Student(int age, const string& name);

	bool operator==(const Student& rhs);



public:
	int	         _Age;
	std::string  _Name;
};

#endif