#include "offer.h"
#include <stdio.h>

namespace Offer
{
	/*
		1��ͷ�����Ҫʹ��ָ���ָ�룬��Ϊ�����ֱ��ʹ��ָ�룬����ɾ������ͷ��㣬
			�����÷����ڣ�ͷ���仯�ˣ��������ߵ�ͷ���û�б仯
		2��ע����Ч�Լ��
		3��ע��ɾ��ͷ���
	*/
	void DeleteNode(ListNode** pPHead,ListNode* delNode)
	{
		// ��Ч�Լ��
		if(pPHead == NULL || delNode==NULL)
		{
			printf("param error");
			return;
		}

		ListNode* curNode = *pPHead;
		if(curNode == delNode) //ɾ��ͷ��㣬���⴦��һ��
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
				break; // �ҵ�֮��break
			}
			curNode = curNode->_PNext;
		}
	}

	/*
		1��DeleteNode�����ڵ㣬�ҵ�Ŀ�꣬Ȼ��ɾ����ʱ��ΪO(n)
		2����û�и��õİ취�أ�
			˼·�ǣ��ҵ���ɾ���ڵ����һ���ڵ㣬��һ��
			��һ���ڵ㸲�Ǵ�ɾ���ڵ㣬Ȼ��ɾ����һ���ڵ�
		3�������˼·����һ�������Ҫ����Դ���
			ɾ������β�ڵ㣬û����һ���ڵ㣬��������һ���ڵ㸲��
		4��ע�⣺����˼·��һ��������������Ҫ�����߱�֤���Ǿ������������ɾ���ڵ㡣
	*/
	void DeleteNode_2(ListNode** pPHead,ListNode* delNode)
	{
		// ��Ч�Լ��
		if(*pPHead == NULL || delNode==NULL)
		{
			printf("param error");
			return;
		}

		ListNode* curNode = *pPHead;
		if(curNode == delNode) //ɾ��ͷ��㣬���⴦��һ��
		{	
			*pPHead = delNode->_PNext;
			delete delNode;
			delNode = NULL;			
			return;
		}

		// �������ٰ��������ڵ�
		if(delNode->_PNext == NULL) // ɾ��β�ڵ�
		{
			while(curNode->_PNext !=NULL)
			{
				if(curNode->_PNext->_PNext == NULL)
				{
					delete delNode;
					curNode->_PNext = NULL;
					break; // �ҵ�֮��break
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


		// |x|>0.1 �ȼ��� x>0.1||x<-0.1
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
		// ÿ�ηָ���±�
		int index = 0;
		//�൱����һ�εķָ���ڵڼ���λ�ã�
		//ȡ���ڵ�ǰ�ָ��left����Ϊÿ�ηָ��Ŀ��ζ��ǲ�һ���ġ�
		int n = 0;

		if(left<right)    
		{    
			index = Partition(a,left,right);    
			n = index-left+1; //���ڵڼ���λ��

			if(n==k)  
			{
				return index; //���ص�k��λ��
			}
			//ǰ��һ�ηָ�Ĵ���̫���ˣ������ָ�ǰһ�Σ�ȥ��С����
			else if(n>k)
			{
				return FindKMax(a,left,index,k); 
			}
			//ǰ��һ�ηָ�Ĵ���̫���ˣ�����k�����ں���һ���У��ٷָ��k-n��������
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

		while(i<j) // ǰ��л���ֱ������
		{				
			while(i<j && a[j]<target)
			{
				--j;
			}
			if(i<j) // û������
			{
				a[i++] = a[j]; //�Ӻ����ڸ���������ǰ��Ŀ�
			}

			while(i<j && a[i]>target)
			{
				++i;
			}

			if(i<j) // û������
			{
				a[j--]=a[i]; //��ǰ���ڸ��������Ϻ���Ŀ�
			}	
		}
		a[i] = target; // ���������Ŀ�
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
		// ʹ���һ���ַ���Ч���ﵽɾ�����һ���ַ���Ŀ��
		// �������ַ�ʽ�����⣬��Ϊsrc��sizeû�б仯
		//src[src.size()-1]=0;
	}
	
	/*
		�����int* q ��һά���飬����4�ʺ󣬾���q[4] 
		��������Ҫ��ά�����ʾ���̣��������˼򻯡�����4�ʺ�
		ʹ��һά���飬q[4]�ĸ�Ԫ�أ���ʾ4�У�a[0]��ֵ��ʾ��0�У�Queen���ڵڼ���
		����a[0]=2, ��ʾ��0�У�Queen���ڵ�2��
	*/
	int* q; 	

	//���һ����
	void PrintQueen_N(int n)  
	{
		static int count = 0;  //������ͬʱ����¼��ĸ���
		printf("��[%d]���⣺",++count);  
		for(int i=0;i<n;i++)
		{
			printf("(%d,%d) ",i,q[i]); 
		}		
		printf("\n"); 

		for(int i=0;i<n;i++)	// ������
		{                  
			for(int j=0;j<n;j++) // ������
			{  
				if(q[i]==j) // ����е�ȡֵ���ڵ�ǰ�У�˵�����λ��,����Queen
				{
					printf("�� "); 					
				}				 
				else 
				{
					printf("�� "); 
				}				
			}  
			printf("\n");  
		}  
	} 

	/*
		����ڵ�row�еĵ�col�У�����Queen�Ƿ�Ϸ�
		��μ�飿
		ǰ���row-1���Ѿ�������Queen��������ЩQueen�����Queen�뵱ǰλ��(row,col)�Ƿ��ͻ
	*/
	bool IsValid(int row,int col)    
	{
		// ����ÿһ�е�Queen
		for(int i=0;i<row;++i)
		{
			/*
				���Queen�뵱ǰλ���Ƿ��ͻ
				��Ϊһ��һ�еط���Queen���϶�����ͬһ����
				Ҫ����Ƿ���ͬһ�л����ڶԽ����ϡ�
				ͬһ�У�q[i]==col ��i��Queen�ŵ��е��ڵ�ǰ��
				�Խ��ߣ����ϵ����£���-��==��-��
						 ���µ����ϣ���-��==-(��-��)
						 Ҳ����abs(r1-r2)=abs(c1-c2)
			*/
			if(q[i]==col || abs(i-row)==abs(q[i]-col)) // λ�ò��Ϸ�
			{
				return false;
			}
		}
		return true;
	}

	// ��ÿһ�з���Queen 
	void PlaceQueenInRow(int row,int n)    
	{		
		if(row>=n) // ��0�п�ʼ���Ѿ��ŵ���n�У����ý���
		{
			PrintQueen_N(n);  
		}		
		else // �ڵ�row�з���Queen
		{
			// ���ڵ�row�У��������е��У��������
			for(int j=0;j<n;j++)  
			{  
				if(IsValid(row,j)) // �ж�row��j�з���Queen�ͷ�Ϸ�
				{
					q[row] = j;    //�Ϸ�����ʶ��row��Queen���ڵ�j��
					PlaceQueenInRow(row+1,n);  //����һ�з���  
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