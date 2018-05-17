#include "offer.h"
#include <stdio.h>

namespace Offer
{
	/*
		1、头结点需要使用指针的指针，因为：如果直接使用指针，并且删除的是头结点，
			被调用方法内，头结点变化了，而调用者的头结点没有变化
		2、注意有效性检查
		3、注意删除头结点
	*/
	void DeleteNode(ListNode** pPHead,ListNode* delNode)
	{
		// 有效性检查
		if(pPHead == NULL || delNode==NULL)
		{
			printf("param error");
			return;
		}

		ListNode* curNode = *pPHead;
		if(curNode == delNode) //删除头结点，特殊处理一下
		{
			*pPHead = delNode->_PNext;
			delete delNode;
			delNode = NULL;			
			return;
		}

		while(curNode!=NULL)
		{
			if(curNode->_PNext == delNode)
			{
				ListNode* nextNode = delNode->_PNext;
				curNode->_PNext = nextNode;
				delete delNode;
				delNode = NULL;
				break; // 找到之后，break
			}
			curNode = curNode->_PNext;
		}
	}

	/*
		1、DeleteNode遍历节点，找到目标，然后删除，时间为O(n)
		2、有没有更好的办法呢？
			思路是：找到待删除节点的下一个节点，捏到一起，
			下一个节点覆盖待删除节点，然后删除下一个节点
		3、上面的思路，有一种情况需要特殊对待。
			删除的是尾节点，没有下一个节点，不能拿下一个节点覆盖
		4、注意：这种思路有一个假设条件，需要调用者保证：那就是链表包含待删除节点。
	*/
	void DeleteNode_2(ListNode** pPHead,ListNode* delNode)
	{
		// 有效性检查
		if(*pPHead == NULL || delNode==NULL)
		{
			printf("param error");
			return;
		}

		ListNode* curNode = *pPHead;
		if(curNode == delNode) //删除头结点，特殊处理一下
		{	
			*pPHead = delNode->_PNext;
			delete delNode;
			delNode = NULL;			
			return;
		}

		// 链表至少包含两个节点
		if(delNode->_PNext == NULL) // 删除尾节点
		{
			while(curNode->_PNext !=NULL)
			{
				if(curNode->_PNext->_PNext == NULL)
				{
					delete delNode;
					curNode->_PNext = NULL;
					break; // 找到之后，break
				}
				curNode = curNode->_PNext;
			}
			return;
		}

		ListNode* nextNode = delNode->_PNext;
		*delNode = *nextNode;
		delete nextNode;		
	}

	


	double GetSqrt(int n)
	{
		double left = 0;
		double right = n;
		double mid = (left+right)/2;


		// |x|>0.1 等价于 x>0.1||x<-0.1
		while(0.00001< mid*mid-n || mid*mid-n < -0.000001)
		{
			if(mid*mid > n)
			{
				right = mid;
			}
			else
			{
				left = mid;
			}
			mid = (left+right)/2;
		}
		return mid;
	}


	int  FindKMax(int* a,int left,int right,int k)
	{
		// 每次分割后下标
		int index = 0;
		//相当于这一次的分割，处于第几个位置，
		//取决于当前分割的left，因为每次分割的目标段都是不一样的。
		int n = 0;

		if(left<right)    
		{    
			index = Partition(a,left,right);    
			n = index-left+1; //处于第几个位置

			if(n==k)  
			{
				return index; //返回第k个位置
			}
			//前面一段分割的大数太多了，继续分割前一段，去掉小的数
			else if(n>k)
			{
				return FindKMax(a,left,index,k); 
			}
			//前面一段分割的大数太少了，不够k个，在后面一段中，再分割出k-n个最大的数
			else 
			{
				return FindKMax(a,index+1,right,k-n);
			}				
		}
		return index;
	}

	int Partition(int a[], int left,int right)    
	{    
		int i = left;
		int j = right;
		int target = a[i];    

		while(i<j) // 前后夹击，直到相遇
		{				
			while(i<j && a[j]<target)
			{
				--j;
			}
			if(i<j) // 没有相遇
			{
				a[i++] = a[j]; //从后面挖个数，填上前面的坑
			}

			while(i<j && a[i]>target)
			{
				++i;
			}

			if(i<j) // 没有相遇
			{
				a[j--]=a[i]; //从前面挖个数，填上后面的坑
			}	
		}
		a[i] = target; // 填上遗留的坑
		return i; 
	}

	void GetPowerSetByBTree(int i,const string& src,string& oneEle,vector<string>& powerSet)
	{
		if(i>=src.size())
		{
			powerSet.push_back(oneEle);
		}
		else
		{
			oneEle+=src[i];
			GetPowerSetByBTree(i+1,src,oneEle,powerSet);

			//oneEle=oneEle.substr(0,oneEle.size()-1);
			oneEle.erase(oneEle.size()-1);
			GetPowerSetByBTree(i+1,src,oneEle,powerSet);
		}
	}


	void GetPowerSet(const string& src,vector<string>& powerSet)
	{
		string oneEle;
		GetPowerSetByBTree(0,src,oneEle,powerSet);
	}

	void RemoveLastElement(string& src)
	{
		if(src.size() == 0)
		{
			return;
		}

		//src = src.substr(0,src.size()-1);
		//src.erase(src.size()-1);
		//src.erase(--src.end());
		src.resize(src.size()-1);
		// 使最后一个字符无效，达到删除最后一个字符的目的
		// 但是这种方式有问题，因为src的size没有变化
		//src[src.size()-1]=0;
	}
	
	/*
		这里的int* q 是一维数组，对于4皇后，就是q[4] 
		按道理需要二维数组表示棋盘，这里做了简化。比如4皇后，
		使用一维数组，q[4]四个元素，表示4行，a[0]的值表示第0行，Queen放在第几列
		比如a[0]=2, 表示第0行，Queen放在第2列
	*/
	int* q; 	

	//输出一个解
	void PrintQueen_N(int n)  
	{
		static int count = 0;  //输出解的同时，记录解的个数
		printf("第[%d]个解：",++count);  
		for(int i=0;i<n;i++)
		{
			printf("(%d,%d) ",i,q[i]); 
		}		
		printf("\n"); 

		for(int i=0;i<n;i++)	// 遍历行
		{                  
			for(int j=0;j<n;j++) // 遍历列
			{  
				if(q[i]==j) // 如果行的取值等于当前列，说明这个位置,放置Queen
				{
					printf("● "); 					
				}				 
				else 
				{
					printf("○ "); 
				}				
			}  
			printf("\n");  
		}  
	} 

	/*
		检查在第row行的第col列，放置Queen是否合法
		如何检查？
		前面的row-1行已经放置了Queen，遍历这些Queen，检查Queen与当前位置(row,col)是否冲突
	*/
	bool IsValid(int row,int col)    
	{
		// 遍历每一行的Queen
		for(int i=0;i<row;++i)
		{
			/*
				检查Queen与当前位置是否冲突
				因为一行一行地放置Queen，肯定不在同一行了
				要检查是否在同一列或者在对角线上。
				同一列：q[i]==col 第i行Queen放的列等于当前列
				对角线：左上到右下，行-行==列-列
						 左下到右上，行-行==-(列-列)
						 也就是abs(r1-r2)=abs(c1-c2)
			*/
			if(q[i]==col || abs(i-row)==abs(q[i]-col)) // 位置不合法
			{
				return false;
			}
		}
		return true;
	}

	// 在每一行放置Queen 
	void PlaceQueenInRow(int row,int n)    
	{		
		if(row>=n) // 从0行开始，已经放到第n行，放置结束
		{
			PrintQueen_N(n);  
		}		
		else // 在第row行放置Queen
		{
			// 对于第row行，遍历所有的列，逐个尝试
			for(int j=0;j<n;j++)  
			{  
				if(IsValid(row,j)) // 判断row的j列放置Queen和否合法
				{
					q[row] = j;    //合法，标识第row的Queen放在第j列
					PlaceQueenInRow(row+1,n);  //在下一行放置  
				}  
			}  
		}  
	}

	void Queen_N(int queenNum)
	{
		q = new int[queenNum];
		PlaceQueenInRow(0,queenNum);
		delete[] q;
	}
}