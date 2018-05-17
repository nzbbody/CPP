#include "opt_file.h"

#include <sys/stat.h>
#include <io.h>
#include <fcntl.h>

namespace OptFile
{
	void ReadFromFile(const string& filePath,string& outStr)
	{
		/*
			�ļ��򿪷�ʽ��r,w,a,t,b��+�����ַ�ƴ�ɣ����ַ��ĺ����ǣ�
			r(read):	��
			w(write):	д
			a(append):	׷��
			t(text):	�ı��ļ�����ʡ�Բ�д
			b(banary):	�������ļ�
			+:			����д
		*/
		FILE* pFile = fopen(filePath.c_str(), "r"); // ��ȡ�ļ�
		if (pFile == NULL)
		{
			return;
		}
		// ���ļ���β�����ƫ��0���ֽڣ�Ҳ�����Ƶ��ļ���β
		if (fseek(pFile, 0, SEEK_END) == -1) 
		{
			return;
		}

		// ��ȡ��ǰλ�ã�Ҳ�����ļ����ֽڸ���
		fpos_t fPos = 0;
		fgetpos(pFile, &fPos);

		// ���ļ���ͷ�����ƫ��0���ֽڣ�Ҳ�����Ƶ��ļ���ͷ
		fseek(pFile, 0, SEEK_SET);

		// ��̬�����ڴ�,
		char* buf = (char *)malloc(fPos+1); //Ҫ�����һ���ֽڱ���\0
		memset(buf, 0, fPos+1);

		// ���ļ������뵽buf�У�ÿ�ζ�ȡһ���ֽڡ�sizeof(char)��,��ȡfPos��
		fread(buf, sizeof(char), fPos, pFile);
		outStr = buf;

		fclose(pFile); // ��Ҫ����close�ļ����
		free(buf); // ��Ҫ�����ͷţ�ʹ��free��malloc��Ӧ
	}

	void ReadFromFile_2(const string& filePath,string& outStr)
	{
		FILE* pFile = fopen(filePath.c_str(), "rb"); // ��ȡ�ļ�
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

		
		fclose(pFile); // ��Ҫ����close�ļ����
		delete []buf; // ��Ҫ�����ͷţ�ʹ��free��malloc��Ӧ
	}






	void ReadFromFile_ByByte(const string& filePath,string& outStr)
	{
		FILE* pFile = fopen(filePath.c_str(), "r"); // ��ȡ�ļ�
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

		fclose(pFile); // ��Ҫ����close�ļ����
	}

	void WriteToFile(const string& filePath,const string& inStr)
	{
		static FILE* pFile = fopen(filePath.c_str(), "a+"); // д�ļ�
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
		// linux�µ�fpos_t�Ǹ��ṹ�壬������
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