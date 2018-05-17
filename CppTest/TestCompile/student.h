#ifndef STUDENT_H_
#define STUDENT_H_

class Student
{
public:
	Student();
	Student(int age);
	~Student();

public:
	void Say();
	bool IsAgeBig(const Student& rhs);

public:
	int _age;
};

class Tmp
{
public:
	bool IsAgeBig(const Student& rhs);
};

#endif