// Sort.cpp : Defines the entry point for the console application.
//

#include "sort.h"
#include <stdlib.h>
#include <time.h>
#include <windows.h>

using namespace std;

template <typename T>
bool Test(vector<T>& srcVec,vector<T>& expectedVec)
{
	if(srcVec.size() != expectedVec.size())
	{
		return false;
	}

	for(int i =0;i<srcVec.size();++i)
	{
		if(srcVec[i] != expectedVec[i])
		{
			return false;
		}
	}

	return true;
}

void PrintVec(vector<int>& cpyVec)
{
	for(vector<int>::iterator iter = cpyVec.begin();
		iter != cpyVec.end(); ++iter)
	{
		printf("%d ",*iter);
	}
	printf("\n");
}


void RandomVec(vector<int>& cpyVec)
{
	srand(time(NULL));
	for(vector<int>::iterator iter = cpyVec.begin();
		iter != cpyVec.end(); ++iter)
	{
		int index = rand()%cpyVec.size();
		swap(*iter,*(cpyVec.begin()+index));

	}

	printf("Before Sort:\n");
	PrintVec(cpyVec);
}





int main(int argc, char* argv[])
{
	//int intArray[] ={1,5,6,8,3,4,9,11};
	//vector<int> aVec(intArray,intArray+sizeof(intArray)/sizeof(int));
	//vector<int> bVec;
	//bVec.resize(aVec.size());

	//Niuzb::Algorithm::Merge(aVec,bVec,0,4,8);







	
	vector<int> intVec;
	for(int i=0;i<100;++i)
	{
		intVec.push_back(i);
	}

	vector<int> cpyVec = intVec;

	RandomVec(cpyVec);


	//Niuzb::Algorithm::BubbleSort(cpyVec);
	//Niuzb::Algorithm::BubbleSort_2(cpyVec);
	//Niuzb::Algorithm::InsertSort(cpyVec);
	//Niuzb::Algorithm::ShellSort(cpyVec);
	//Niuzb::Algorithm::SelectSort(cpyVec);
	//Niuzb::Algorithm::QuickSort(cpyVec);
	//Niuzb::Algorithm::HeapSort(cpyVec);
	//Niuzb::Algorithm::MergeSort(cpyVec);
	Niuzb::Algorithm::MergeSort_2(cpyVec);

	printf("After Sort:\n");
	PrintVec(cpyVec);
	if(Test(intVec,cpyVec))
	{
		printf("Test Sort OK\n");
	}
	else
	{
		printf("Test Sort ERROR\n");
	}
	
	getchar();

	return 0;
}
