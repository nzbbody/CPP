#include <stdio.h>
#include <string.h>
#include <time.h>


int main(int argc,char* argv)
{
	int	bufSize = 64; 
	char* buf = new char[bufSize];
	memset(buf,0,bufSize);

	FILE* pFile = fopen("aaa.txt","r");

	printf("[%d] Start Read\n",(int)time(NULL));
	while(feof(pFile) == false)
	{
		int readed = fread(buf,3,3,pFile);
		printf("readed[%d]\n",readed);
	}
	printf("[%d] Stop  Read\n",(int)time(NULL));

	fclose(pFile);
	getchar();

	return 0;
}


/*
int main(int argc,char* argv)
{
	int	bufSize = 8; 
	char* buf = new char[bufSize];
	//memset(buf,'a',bufSize);
	sprintf(buf,"1234567");

	FILE* pFile = fopen("aaa.txt","wt");

	printf("[%d] Start Write\n",(int)time(NULL));
	for(int i = 0; i<1024*1024*64; ++i)
	{
		int writed = fwrite(buf,bufSize,1,pFile);
		fflush(pFile);
	}
	printf("[%d] Stop  Write\n",(int)time(NULL));

	fclose(pFile);
	getchar();

	return 0;
}
*/


/*
int main(int argc,char* argv)
{
	int	bufSize = 1024*1024; 
	char* buf = new char[bufSize];
	memset(buf,'a',bufSize);

	FILE* pFile = fopen("aaa.txt","wb");

	printf("[%d] Start Write\n",(int)time(NULL));
	for(int i = 0; i<128; ++i)
	{
		int writed = fwrite(buf,1,bufSize,pFile);
		fflush(pFile);
	}
	printf("[%d] Stop  Write\n",(int)time(NULL));

	fclose(pFile);

	return 0;
}
*/
















/*
#include "opt_file.h"
#include <time.h>
*/























/*
#define SizeForOneRead 1024*1024

int main()
{
	string fileName = "E:/tmp/92.dav";
	FILE* fileHandle = fopen(fileName.c_str(), "rb"); // 读取文件

	printf("[%d] Start Read File[%s] FileHandle[%p]\n",
		(int)time(NULL),
		fileName.c_str(),
		fileHandle);

	int readCount = 0;

	char* buf = new char[SizeForOneRead];
	while(feof(fileHandle) == false)
	{
		memset(buf,0,SizeForOneRead);
		int readed = fread(buf,SizeForOneRead,1,fileHandle); //一次读取多个
		//int readed = fread(buf,1,SizeForOneRead,fileHandle);   //多次读取
		readCount+=readed;
	}

	printf("[%d] Stop  Read File[%s] FileHandle[%p] ReadCount[%d]\n",
		(int)time(NULL),
		fileName.c_str(),
		fileHandle,
		readCount);

	getchar();
	return 0;
}
*/

/*
int main(int argc,char* argv[])
{
	//TestReadFile();

	//int dd = time(NULL);



	//int size = OptFile::GetFieSize("./read133.txt");

	//int size = OptFile::GetFieSize("read1.txt");

	

	string str;
	OptFile::ReadFromFile_2("./write3.txt",str);
	//OptFile::ReadFromFile("./read1.txt",str);
	//OptFile::ReadFromFile_ByByte("./read1.txt",str);

	
	OptFile::WriteToFile_2("./write1.txt","111");
	OptFile::WriteToFile_2("./write1.txt","222");
	OptFile::WriteToFile_2("./write1.txt","111");

	OptFile::WriteToFile("./write1.txt","1234567");

	//getchar();
	return 0;
}
*/