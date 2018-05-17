#ifndef OFFER_H_
#define OFFER_H_
#include <stdlib.h>
#include <string>
#include <vector>

namespace Offer
{
	using namespace std;

	struct ListNode
	{
		int			_Value;
		ListNode*	_PNext;

		ListNode():_Value(0),_PNext(NULL)
		{
		}

		ListNode(int value,ListNode* pNext):_Value(value),_PNext(pNext)
		{
		}
	};


	// 删除链表节点
	void DeleteNode(ListNode** pPHead,ListNode* delNode);
	void DeleteNode_2(ListNode** pPHead,ListNode* delNode);


	// 使用牛顿迭代，获取平方根
	double  GetSqrt(int n);

	int  FindKMax(int* a,int left,int right,int k);
	int  Partition(int a[], int left,int right);
	
	void GetPowerSetByBTree(int i,const string& src,string& oneEle,vector<string>& powerSet);

	void GetPowerSet(const string& src,vector<string>& powerSet);

	void RemoveLastElement(string& str);

	void PrintQueen_N(int n);

	bool IsValid(int row,int col);

	void PlaceQueenInRow(int row,int n); 

	void Queen_N(int queenNum);
}
#endif