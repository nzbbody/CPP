#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "offer.h"
#include <list>

using namespace Offer;

void BubbleSort(int* pInt,int len)
{
	if(pInt == NULL)
	{
		return;
	}

	for(int i=0;i<len;++i)
	{
		for(int j=0;j<len-i-1;++j)
		{
			if(pInt[j]>pInt[j+1])
			{
				int tmp = pInt[j];
				pInt[j] = pInt[j+1];
				pInt[j+1] = tmp;
			}
		}
	}

}


/*
int main(int argc, char* argv[])
{
	int len = argc-1;

	int* pInt = new int[len];
	memset(pInt,0,len*4);

	for(int i=0;i<len;++i)
	{
		pInt[i] = atoi(argv[i+1]);
	}

	BubbleSort(pInt,len);

	for(int i =0;i<len;++i)
	{
		printf("%d ",pInt[i]);
	}

	getchar();
		
	return 0;
}
*/

void PrintListNode(ListNode* pFirst)
{
	while(pFirst!=NULL)
	{
		printf("%d ",pFirst->_Value);
		pFirst=pFirst->_PNext;
	}
	printf("\n");
}

void Test()
{
	ListNode* n6 = new ListNode(6,NULL);
	ListNode* n5 = new ListNode(5,n6);
	ListNode* n4 = new ListNode(4,n5);
	ListNode* n3 = new ListNode(3,n4);
	ListNode* n2 = new ListNode(2,n3);
	ListNode* n1 = new ListNode(1,n2);

	PrintListNode(n1);
	DeleteNode_2(&n1,n6);
	PrintListNode(n1);

	ListNode* curNode = n1;
	ListNode* next=NULL;
	while(curNode!=NULL)
	{
		next=curNode->_PNext;
		delete curNode;
		curNode=next;
	}
	curNode=NULL;
}


int main(void)  
{
	Queen_N(8);

	system("pause");  
	return 0;  
} 


/*
int main(int argc, char* argv[])
{
	string aStr ="abc";
	RemoveLastElement(aStr);
	int dd = aStr.size();

	vector<int> intVec;
	intVec.push_back(1);
	intVec.push_back(2);
	intVec.push_back(3);
	
	intVec.erase(--intVec.end());
	//intVec.resize(intVec.size()-1);
	dd = intVec.size();


	list<int> intList;
	intList.push_back(1);
	intList.push_back(2);
	intList.push_back(3);

	//intList.erase(--intList.end());
	intList.resize(intList.size()-1);
	dd = intList.size();

	//src = src.substr(0,src.size()-1);
	//src.erase(src.size()-1);
	//src.erase(--src.end());
	//src.resize(src.size()-1);
	
	getchar();
	return 0;
}
*/


/*
int main(int argc, char* argv[])
{
	//Test();

	//Male mm = (Male)(0);

	//double dd = GetSqrt(3);

	string ss = "abc";
	vector<string> powerSet;
	GetPowerSet(ss,powerSet);


	int a[] = {5,100,3,1,7,456,9,2,4,45,6,8};

	int index = FindKMax(a,0,sizeof(a)/sizeof(int)-1,1);
	
	getchar();

	return 0;
}
*/
