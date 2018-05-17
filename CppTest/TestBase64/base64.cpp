#include "Base64.h"


using namespace std;

void Base64::Encode(string& outStr, const unsigned char* inData,int inSize)
{
	//编码表
	//编码的时候a[0]=A
	const char EncodeTable[]="ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";

	unsigned char a1;
	unsigned char a2;
	unsigned char a3;

	int groupSize = inSize/3;


	int LineLength=0;

	for(int i=0; i<groupSize; i++)
	{
		a1 = *inData++;
		a2 = *inData++;
		a3 = *inData++;
		outStr+= EncodeTable[a1 >> 2];
		outStr+= EncodeTable[((a1 << 4) | (a2>> 4)) & 0x3F];
		outStr+= EncodeTable[((a2 << 2) | (a3 >> 6)) & 0x3F];
		outStr+= EncodeTable[a3 & 0x3F];		
	}
	//对剩余数据进行编码
	int mod=inSize % 3;
	if(mod==1)
	{
		a1 = *inData++;
		outStr+= EncodeTable[(a1 & 0xFC) >> 2];
		outStr+= EncodeTable[((a1 & 0x03) << 4)];
		outStr+= "==";
	}
	else if(mod==2)
	{
		a1 = *inData++;
		a2 = *inData++;
		outStr+= EncodeTable[(a1 & 0xFC) >> 2];
		outStr+= EncodeTable[((a1 & 0x03) << 4) | ((a2 & 0xF0) >> 4)];
		outStr+= EncodeTable[((a2 & 0x0F) << 2)];
		outStr+= "=";
	}
}

void Base64::Decode(const string& inStr, unsigned char*& outData,int& outSize)
{
	unsigned char* inData = (unsigned char*)(inStr.c_str());
	int inSize = inStr.size();

	outSize = 0;

	//解码表
	//解码的时候a[A]=0，也就是a[65]=0
	const char DecodeTable[] =
	{
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		62, // '+'
		0, 0, 0,
		63, // '/'
		52, 53, 54, 55, 56, 57, 58, 59, 60, 61, // '0'-'9'
		0, 0, 0, 0, 0, 0, 0,
		0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12,
		13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, // 'A'-'Z'
		0, 0, 0, 0, 0, 0,
		26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38,
		39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 51, // 'a'-'z'
	};

	int nValue;
	int i= 0;
	while (i < inSize)
	{
		if (*inData != '\r' && *inData!='\n')
		{
			nValue = DecodeTable[*inData++] << 18;
			nValue += DecodeTable[*inData++] << 12;
			outData[outSize++]=(nValue & 0x00FF0000) >> 16;

			if (*inData != '=')
			{
				nValue += DecodeTable[*inData++] << 6;
				outData[outSize++]=(nValue & 0x0000FF00) >> 8;

				if (*inData != '=')
				{
					nValue += DecodeTable[*inData++];
					outData[outSize++]=nValue & 0x000000FF;
				}
				else
				{
					printf("Meet 4Th =");
				}
			}
			else
			{
				printf("Meet 3Th =");
			}
			i += 4;
		}
		else// 回车换行,跳过
		{
			inData++;
			i++;
		}
	}
}