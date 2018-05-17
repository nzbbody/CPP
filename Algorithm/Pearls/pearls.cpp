#include "pearls.h"
#include <time.h>

namespace Pearls
{
	#pragma region 1���������� 
	void SetBitValue(uint_8* start,int index,int value)
	{		
		int bytePos = index/8; // �ڼ����ֽ�
		int bitPos  = index%8; // �ֽ��ڵĵڼ���bit

		start+=bytePos;
		if(value == 0)
		{
			(*start)&=(~(1<<bitPos)); // ��ĳһ��bit�ó�0������һ����Ӧλ��0������λ��1�����������и�ȡ��
		}
		else if(value == 1)
		{
			(*start)|=(1<<bitPos);   // ��ĳһ��bit�ó�1������һ����Ӧλ��1������λ��0����
		}		
	}

	int GetBitValue(uint_8* start,int index)
	{		
		int bytePos = index/8; // �ڼ����ֽ�
		int bitPos  = index%8; // �ֽ��ڵĵڼ���bit

		// ����������ת��Ϊunsigned������λ
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
	#pragma endregion 1����������

	#pragma region ��λ��
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
		buf[strlen(buf)-1] = '\0'; //ȥ���ָ���
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
	#pragma endregion ��λ��

	#pragma region ѭ����λ
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

		// ÿ������һλ��ѭ��n��
		//for(int i=0;i<moveSize;++i)
		//{
		//	char first = pc[0];
		//	for(int j=0;j<len-1;++j)
		//	{
		//		pc[j]=pc[j+1];
		//	}
		//	pc[len-1]=first;
		//}

		// һ������nλ
		//char* buf = new char[moveSize];
		//memset(buf,0,moveSize);
		//memcpy(buf,pc,moveSize);

		//for(int j=0;j<len-moveSize;++j)
		//{
		//	pc[j]=pc[j+moveSize];
		//}
		//memcpy(pc+len-moveSize,buf,moveSize);

		// ��ת����
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
	#pragma endregion ѭ����λ

	#pragma region ȫ����
	void PrintTotalOrder(const string& str)
	{
		//PrintOrder("",str);

		PrintOrder_2(str);
	}

	void PrintOrder(const string& prefix,const string& other)
	{
		if (other.size()==1)  
		{  
			//�����׺ֻʣһ���ַ��������ǰ˳�򣬵ݹ����  
			printf("%s%s\n",prefix.c_str(),other.c_str());  
		}  
		else  
		{  
			//�����׺���ȴ���1��ÿ�ΰѺ�׺�е�һ���ַ���ӵ�ǰ׺�У��ݹ�  
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

		// �Ӻ���ǰ���ҵ���һ��λ�ã����λ�õ�Ԫ��С����һ��λ�õ�Ԫ��
		int pos = len-2; // �ٶ��ǵ����ڶ���Ԫ��
		while(pos>=0 && str[pos]>str[pos+1]) // ��������������ǰ�ƶ�
		{
			--pos;
		}

		if(pos==-1) // λ�ò����ڣ��Ѿ����������У�ȡֵ���
		{
			return false;
		}
		else		
		{
			// �Ӻ����ҳ�һ���ȵ�ǰ�±���Ԫ�����backpos�ض����ڡ�
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

	// ��string��left��right���䷴ת
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
			Swap(str[i],str[--right]); // left�±��1��right�±��1
		}
	}

	#pragma endregion ȫ����

	#pragma region ͳ���ַ�����
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
		// ���512���ַ����±��Ӧ�ַ����±�ȡֵ��Ӧ���ֵĴ���
		int hashTable[512]={0};

		for(int i = 0;i<str.size();++i)
		{
			hashTable[str[i]]++;
		}

		for(int i=0; i<512; ++i)
		{
			if(hashTable[i]>0) // ���ֹ�
			{
				printf("[%c:%d]\n",i,hashTable[i]);
			}			
		}
	}
	#pragma endregion ͳ���ַ�����


	#pragma region �����
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

	// ����һ����ά���飬��һ�β����������ڶ��β����еĵڼ���Ԫ�ء�
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
	#pragma endregion �����

	#pragma region ȡ��
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
	#pragma endregion ȡ��

}