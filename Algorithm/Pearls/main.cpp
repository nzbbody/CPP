
#include "pearls.h"

#include <stdio.h>
#include <string.h>
#include <fstream>
#include "iostream"  

using namespace std;  	
	
int main(int argc, char*argv[])
{
	string str = "acbbdkdehfghgefahb";
	Pearls::GetCharCountByMap(str);
	Pearls::GetCharCountByHashTable(str);

	getchar();
	return 0;
}




/*
int main(int argc, char*argv[])
{
	map<int,int> intOccurMap;

	for(int i=0;i<35000;++i)
	{
		intOccurMap[Pearls::Random_7_By_Random_5()]++;
	}

	for(map<int,int>::iterator iter = intOccurMap.begin();
		iter != intOccurMap.end(); ++iter)  
	{
		printf("%d[%d]\n",
			iter->first,
			iter->second);
	}

	getchar();
	return 0;
}
*/

/*
int main(int argc, char*argv[])
{
	map<int,int> intOccurMap;

	vector<int> intVec;


	for(int i=0;i<7000;++i)
	{
		//printf("µÚ%d´Î£º",i);

		Pearls::Select_2_From_7(intVec);
		for(vector<int>::iterator iter = intVec.begin();
			iter != intVec.end(); ++iter)
		{
			//printf("%d ",*iter);

			intOccurMap[*iter]++;
		}
		//printf("\n");
	}

	for(map<int,int>::iterator iter = intOccurMap.begin();
		iter != intOccurMap.end(); ++iter)  
	{
		printf("%d[%d]\n",
			iter->first,
			iter->second);
	}

	getchar();
	return 0;
}


*/


//int main(int argc, char* argv[])
//{
//	Pearls::PrintTotalOrder("1234");
//	getchar();
//	return 0;
//}

/*
int main(int argc, char* argv[])
{
	char buf[] = "abcdefgh";
	Pearls::LoopMove(buf,3);

	Pearls::LoopMove(buf,3);

	Pearls::LoopMove(buf,4);

	Pearls::LoopMove(buf,81);

	getchar();
	return 0;
}
*/

/*
int main(int argc, char* argv[])
{
	vector<string> wordVec;
	Pearls::ReadWordFromFile(wordVec);

	map<string,vector<string> > wordMap;
	for(vector<string>::iterator iter = wordVec.begin();
		iter != wordVec.end();++iter)
	{
		wordMap[Pearls::GetIdentifier(*iter)].push_back(*iter);
	}

	getchar();
	return 0;
}
*/

/*
int main(int argc, char* argv[])
{
	uint_8* bitVec = new uint_8[4];
	memset(bitVec,0,4);

	Pearls::ReadFileAndSetBitVec(bitVec);
	Pearls::PrintBitVec(bitVec);


	getchar();
	return 0;
}
*/
