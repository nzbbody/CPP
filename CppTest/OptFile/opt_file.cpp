#include "opt_file.h"

#include <sys/stat.h>
#include <io.h>
#include <fcntl.h>

namespace OptFile
{
	void ReadFromFile(const string& filePath,string& outStr)
	{
		/*
			文件打开方式由r,w,a,t,b，+六个字符拼成，各字符的含义是：
			r(read):	读
			w(write):	写
			a(append):	追加
			t(text):	文本文件，可省略不写
			b(banary):	二进制文件
			+:			读和写
		*/
		FILE* pFile = fopen(filePath.c_str(), "r"); // 读取文件
		if (pFile == NULL)
		{
			return;
		}
		// 从文件结尾，向后偏移0个字节，也就是移到文件结尾
		if (fseek(pFile, 0, SEEK_END) == -1) 
		{
			return;
		}

		// 获取当前位置，也就是文件的字节个数
		fpos_t fPos = 0;
		fgetpos(pFile, &fPos);

		// 从文件开头，向后偏移0个字节，也就是移到文件开头
		fseek(pFile, 0, SEEK_SET);

		// 动态分配内存,
		char* buf = (char *)malloc(fPos+1); //要多分配一个字节保存\0
		memset(buf, 0, fPos+1);

		// 把文件流读入到buf中，每次读取一个字节【sizeof(char)】,读取fPos次
		fread(buf, sizeof(char), fPos, pFile);
		outStr = buf;

		fclose(pFile); // 不要忘记close文件句柄
		free(buf); // 不要忘记释放，使用free与malloc对应
	}

	void ReadFromFile_2(const string& filePath,string& outStr)
	{
		FILE* pFile = fopen(filePath.c_str(), "rb"); // 读取文件
		if (pFile == NULL)
		{
			return;
		}

		int sizeForOneRead = 4;

		char* buf = new char[sizeForOneRead];
		memset(buf, 0,sizeForOneRead);

		while(feof(pFile) == false)
		{
			int readSize = fread(buf,sizeForOneRead,sizeof(char),pFile);

			int hh = 0;
		}

		printf("%s\n",buf);

		
		fclose(pFile); // 不要忘记close文件句柄
		delete []buf; // 不要忘记释放，使用free与malloc对应
	}






	void ReadFromFile_ByByte(const string& filePath,string& outStr)
	{
		FILE* pFile = fopen(filePath.c_str(), "r"); // 读取文件
		if (pFile == NULL)
		{
			return;
		}
		char ch;

		while(feof(pFile) == false)
		{
			ch = fgetc(pFile);
			outStr+=ch;
		}

		fclose(pFile); // 不要忘记close文件句柄
	}

	void WriteToFile(const string& filePath,const string& inStr)
	{
		static FILE* pFile = fopen(filePath.c_str(), "a+"); // 写文件
		if (pFile == NULL)
		{
			return;
		}
		fwrite(inStr.c_str(), sizeof(char), inStr.size(), pFile);
		fflush(pFile);
		//fclose(pFile);
	}

	void WriteToFile_2(const string& filePath,const string& inStr)
	{
		static FILE* pFile = fopen(filePath.c_str(), "a+");
		if (pFile == NULL)
		{
			return;
		}
		fprintf(pFile,"%s",inStr.c_str());
		fflush(pFile);
		//fclose(pFile);
	}

	int  GetFieSize(const string& filePath)
	{
		// linux下的fpos_t是个结构体，不兼容
		FILE* pFile1 = fopen(filePath.c_str(), "r"); 
		fseek(pFile1, 0, SEEK_END);
		fpos_t fPos = 0;
		fgetpos(pFile1, &fPos);
		fclose(pFile1);
		printf("Method1[%d]",
			fPos);

		FILE* pFile2 = fopen(filePath.c_str(), "r"); 
		fseek(pFile2, 0, SEEK_END);
		int size = ftell(pFile2);
		printf("Method2[%d]",
			size);

		int pFile3 = open(filePath.c_str(),O_RDONLY); 
		int length = filelength(pFile3);
		printf("Method3[%d]",
			length);

		struct stat fileInfo;
		stat(filePath.c_str(),&fileInfo);
		printf("Method4[%d]",
			fileInfo.st_size);
		return fileInfo.st_size;
	}
}