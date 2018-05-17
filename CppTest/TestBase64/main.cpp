// OptFile.cpp : Defines the entry point for the console application.
//

#include "base64.h"
#include <Windows.h>
#include <fstream>

using namespace std;

void TestBase64();
void CreateFile();
void WritePic();
void CopyPic();
void ReadAndWritePic();



int main(int argc, char* argv[])
{
	//TestBase64();

	//CreateFile();

	//WritePic();

	//CopyPic();

	ReadAndWritePic();	

	return 0;
}

void TestBase64()
{
	string str = "";
	unsigned char inData[16] = {255,255,255,255,255};
	Base64::Encode(str,inData,5);


	unsigned char* outData = new unsigned char[str.size()/4*3];
	int outSize = 0;


	Base64::Decode(str,outData,outSize);
}


void CreateFile()
{
	ofstream outFile;
	outFile.open("hhh.jpg");
}


void WritePic()
{
	std::string picData;

	FILE* fPic = fopen("pic1.txt", "rt");
	int sdf = ::GetLastError();
	printf("%d\r\n",fPic);

	char buf[1024*100] = {0};

	if(fPic != NULL)
	{
		while(fgets(buf,1024*100,fPic))
		{
			picData+=buf;
		}
	}	

	unsigned char* outData = new unsigned char[picData.size()/4*3];
	int outSize;

	
	Base64::Decode(picData,outData,outSize);


	FILE* pic = fopen("pic1.jpg", "wb");
	if (pic == NULL)
	{
		return;
	}
	fwrite(outData, sizeof(char), outSize, pic);

	fclose(pic);
}

void CopyPic()
{
	FILE *rPic = fopen("aaa.bmp", "rb"); // 读取二进制文件
	if (rPic == NULL)
	{
		return;
	}
	// 从文件结尾，向后偏移0个字节，也就是移到文件结尾
	if (fseek(rPic, 0, SEEK_END) == -1) 
	{
		return;
	}

	// 获取当前位置，也就是文件的字节个数
	fpos_t fPos = 0;
	fgetpos(rPic, &fPos);

	// 从文件开头，向后偏移0个字节，也就是移到文件开头
	fseek(rPic, 0, SEEK_SET);

	// 动态分配内存
	char *buf = (char *)malloc(fPos * sizeof(char));
	memset(buf, 0, fPos * sizeof(char));

	// 把文件流读入到buf中，每次读取一个字节【sizeof(char)】,读取fPos次
	fread(buf, sizeof(char), fPos, rPic);


	FILE *wPic = fopen("bbb.bmp", "wb");
	if (wPic == NULL)
	{
		return;
	}

	// 把buf写入到wPic中，每次写入一个字节【sizeof(char)】,写入fPos次
	fwrite(buf, sizeof(char), fPos, wPic);
	fclose(wPic);
}




void ReadAndWritePic()
{
	FILE *rPic = fopen("bbb2.bmp", "rb");
	if (rPic == NULL)
	{
		return;
	}
	if (fseek(rPic, 0, SEEK_END) == -1)
	{
		return;
	}
	fpos_t fPos = 0;
	fgetpos(rPic, &fPos);
	fseek(rPic, 0, SEEK_SET);
	char *buf = (char *)malloc(fPos * sizeof(char));
	memset(buf, 0, fPos * sizeof(char));
	fread(buf, sizeof(char), fPos, rPic);

	string base64Str;

	Base64::Encode(base64Str,(unsigned char*)buf,fPos);

	unsigned char* outData = new unsigned char[base64Str.size()/4*3];
	int outSize = 0;

	Base64::Decode(base64Str,outData,outSize);


	FILE *wPic = fopen("bbb1552.bmp", "wb");
	if (wPic == NULL)
	{
		return;
	}
	fwrite(outData, sizeof(char), outSize, wPic);
	fclose(wPic);
}
