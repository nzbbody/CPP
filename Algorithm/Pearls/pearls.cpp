#include "pearls.h"
#include <time.h>

namespace Pearls
{
	#pragma region 1亿整数排序 
	void SetBitValue(uint_8* start,int index,int value)
	{		
		int bytePos = index/8; // 第几个字节
		int bitPos  = index%8; // 字节内的第几个bit

		start+=bytePos;
		if(value == 0)
		{
			(*start)&=(~(1<<bitPos)); // 把某一个bit置成0，与上一个对应位是0，其它位是1的数，这里有个取反
		}
		else if(value == 1)
		{
			(*start)|=(1<<bitPos);   // 把某一个bit置成1，或上一个对应位是1，其它位是0的数
		}		
	}

	int GetBitValue(uint_8* start,int index)
	{		
		int bytePos = index/8; // 第几个字节
		int bitPos  = index%8; // 字节内的第几个bit

		// 做个副本，转化为unsigned，再移位
		uint_8 ch = *(start+=bytePos);
		return ((ch)&=(1<<bitPos))>>bitPos;
	}

	void ReadFileAndSetBitVec(uint_8* bitVec)
	{
		FILE* pf = fopen("./ints.txt","r");
		char readBuf[4] = {0};
		char* pBuf = readBuf;

		while(feof(pf) == false)
		{
			if((*pBuf++ = fgetc(pf)) == ' ')
			{
				int value = atoi(readBuf);
				Pearls::SetBitValue(bitVec,value,1);
				memset(readBuf,0,4);
				pBuf = readBuf;
			}
		}
	}

	void PrintBitVec(uint_8* bitVec)
	{
		for(int i = 0; i<32; ++i)
		{
			int dd = Pearls::GetBitValue(bitVec,i);
			if(Pearls::GetBitValue(bitVec,i) == 1)
			{
				printf("%d ",i);
			}
		}
	}
	#pragma endregion 1亿整数排序

	#pragma region 变位词
	string GetIdentifier(const string& word)
	{
		char buf[64] = {0};
		sprintf(buf,word.c_str());
		qsort(buf,strlen(buf),sizeof(char),CharCmp);

		return buf;
	}

	int CharCmp(const void* a,const void* b)
	{
		return *(char*)a - *(char*)b;
	}

	bool IsSeparator(char ch)
	{
		return (ch == ' ' || ch == ',' || ch == '.'|| ch == '\r'|| ch == '\n');
	}

	void GetWord(vector<string>& wordVec,char* buf)
	{
		buf[strlen(buf)-1] = '\0'; //去除分隔符
		if(strlen(buf) > 0)
		{
			wordVec.push_back(buf);
		}
	}

	void ReadWordFromFile(vector<string>& wordVec)
	{
		FILE* pf = fopen("./words.txt","r");
		char readBuf[64] = {0};
		char* pBuf = readBuf;

		while(feof(pf) == false)
		{
			*pBuf = fgetc(pf);
			if(IsSeparator(*pBuf))
			{
				GetWord(wordVec,readBuf);
				memset(readBuf,0,64);
				pBuf = readBuf;
			}
			else
			{
				++pBuf;
			}
		}
	}
	#pragma endregion 变位词

	#pragma region 循环移位
	void LoopMove(char* pc,int moveSize)
	{
		if(pc == NULL)
		{
			return;
		}
		int len = strlen(pc);
		if(len <= 1)
		{
			return;
		}

		moveSize = moveSize%len;

		// 每次左移一位，循环n次
		//for(int i=0;i<moveSize;++i)
		//{
		//	char first = pc[0];
		//	for(int j=0;j<len-1;++j)
		//	{
		//		pc[j]=pc[j+1];
		//	}
		//	pc[len-1]=first;
		//}

		// 一次左移n位
		//char* buf = new char[moveSize];
		//memset(buf,0,moveSize);
		//memcpy(buf,pc,moveSize);

		//for(int j=0;j<len-moveSize;++j)
		//{
		//	pc[j]=pc[j+moveSize];
		//}
		//memcpy(pc+len-moveSize,buf,moveSize);

		// 反转三次
		Reverse(pc,pc+moveSize);
		Reverse(pc+moveSize,pc+len);
		Reverse(pc,pc+len);
	}

	void Reverse(char* first,char* last)
	{
		int len = last-first;
		for(int i=0;i<len/2;++i)
		{
			char tmp = first[i];
			first[i] = first[len-i-1];
			first[len-i-1]=tmp;
		}
	}
	#pragma endregion 循环移位

	#pragma region 全排列
	void PrintTotalOrder(const string& str)
	{
		//PrintOrder("",str);

		PrintOrder_2(str);
	}

	void PrintOrder(const string& prefix,const string& other)
	{
		if (other.size()==1)  
		{  
			//如果后缀只剩一个字符，输出当前顺序，递归结束  
			printf("%s%s\n",prefix.c_str(),other.c_str());  
		}  
		else  
		{  
			//如果后缀长度大于1，每次把后缀中的一个字符添加到前缀中，递归  
			for (int i=0;i<other.size();i++)  
			{  
				PrintOrder(prefix+other.substr(i,1),string(other).erase(i,1));  
			}  
		}  
	}

	void PrintOrder_2(const string& str)
	{
		vector<string> vec;
		string cpy = str;
		do
		{
			printf("%s\n",cpy.c_str());
			vec.push_back(cpy);
		}while(Next(cpy));
	}

	bool Next(string& str)
	{
		int len = str.size();

		// 从后向前，找到第一个位置，这个位置的元素小于下一个位置的元素
		int pos = len-2; // 假定是倒数第二个元素
		while(pos>=0 && str[pos]>str[pos+1]) // 不满足条件，向前移动
		{
			--pos;
		}

		if(pos==-1) // 位置不存在，已经是逆序排列，取值最大
		{
			return false;
		}
		else		
		{
			// 从后面找出一个比当前下标大的元，这个backpos必定存在。
			int backPos = len-1;
			while(backPos>0 && str[backPos] < str[pos])
			{
				--backPos;
			}
			Swap(str[pos],str[backPos]);

			ReverseString(str,pos+1,str.size());
			return true;
		}
	}

	// 对string的left和right区间反转
	void ReverseString(string& str,int left,int right)
	{
		if(left>right)
		{
			Swap(left,right);
		}

		if(right>str.size())
		{
			return;
		}
		
		int mid = (left+right)/2;
		for(int i = left;i<mid;++i)
		{
			Swap(str[i],str[--right]); // left下标加1，right下标减1
		}
	}

	#pragma endregion 全排列

	#pragma region 统计字符个数
	void GetCharCountByMap(const string& str)	
	{
		map<char,int> chMap;

		for(int i = 0;i<str.size();++i)
		{
			chMap[str[i]]++;
		}

		for(map<char,int>::iterator iter = chMap.begin();
			iter != chMap.end(); ++iter)
		{
			printf("[%c:%d]\n",iter->first,iter->second);
		}
	}


	void GetCharCountByHashTable(const string& str)
	{
		// 最多512个字符，下标对应字符，下标取值对应出现的次数
		int hashTable[512]={0};

		for(int i = 0;i<str.size();++i)
		{
			hashTable[str[i]]++;
		}

		for(int i=0; i<512; ++i)
		{
			if(hashTable[i]>0) // 出现过
			{
				printf("[%c:%d]\n",i,hashTable[i]);
			}			
		}
	}
	#pragma endregion 统计字符个数


	#pragma region 随机数
	int Random_5()
	{
		static bool isFirstCall = true;
		if(isFirstCall)
		{
			srand(time(NULL));
			isFirstCall = false;
		}		
		return rand()%5;
	}

	int Random_7()
	{
		static bool isFirstCall = true;
		if(isFirstCall)
		{
			srand(time(NULL));
			isFirstCall = false;
		}		
		return rand()%7;
	}

	int Random_5_By_Random_7()
	{
		int a = Random_7();
		while(a>=5)
		{
			a=Random_7();
		}
		return a;
	}

	// 想象一个二维数组，第一次产生行数，第二次产生行的第几个元素。
	int Random_7_By_Random_5()
	{
		int row = Random_5();
		int col = Random_5();
		while(row*5+col >= 21)
		{
			row = Random_5();
			col = Random_5();
		}
		return (row*5+col)%7;
	}
	#pragma endregion 随机数

	#pragma region 取样
	int Select_2_From_7(vector<int>& intVec)
	{
		static bool isFirstCall = true;
		if(isFirstCall)
		{
			srand(time(NULL));
			isFirstCall = false;
		}
		
		intVec.clear();

		int total = 7;
		int select = 2;
		for(int i=0;i<total;++i)
		{
			if(rand()%(total-i) <select)
			{
				intVec.push_back(i);
				--select;
			}
		}
		return 0;
	}
	#pragma endregion 取样

}