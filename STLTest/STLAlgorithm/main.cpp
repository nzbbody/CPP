#include "niu_algorithm.h"

#include <list>
using namespace std;


int main(int argc, char* argv[])
{
	int aArr[] = {1,5,3,8,9,7,6};

	int bArr[] = {8,9};

	list<int> aList(aArr,aArr+sizeof(aArr)/sizeof(aArr[0]));
	list<int> bList(bArr,bArr+sizeof(bArr)/sizeof(bArr[0]));

	
	list<int>::iterator iter = Niu_Search(aList.begin(),aList.end(),
		bList.begin(),bList.end());

	//niu_remove(aList.begin(),aList.end(),2);
	
	return 0;
}

