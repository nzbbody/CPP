// CryptDB.cpp : 定义控制台应用程序的入口点。
//

#include <string>

using namespace std;

void Base64_Encode(string& outStr, const unsigned char* inData,int inSize)
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

void Base64_Decode(const string& inStr, unsigned char*& outData,int& outSize)
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



void ReadFromFile(const string& filePath,char*& buf,int& size)
{
    /*
        文件打开方式由r,w,a,t,b，+六个字符拼成，各字符的含义是：
        r(read):    读
        w(write):   写
        a(append):  追加
        t(text):    文本文件，可省略不写
        b(banary):  二进制文件
        +:          读和写
    */
    FILE* pFile = fopen(filePath.c_str(), "rb"); // 读取文件
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
    buf = (char *)malloc(fPos+1); //要多分配一个字节保存\0
    memset(buf, 0, fPos+1);

    // 把文件流读入到buf中，每次读取一个字节【sizeof(char)】,读取fPos次
    fread(buf, sizeof(char), fPos, pFile);
    fclose(pFile); // 不要忘记close文件句柄

	size = fPos; 
}

void WriteToFile(const string& filePath,char* inStr,int size)
{
    FILE* pFile = fopen(filePath.c_str(), "wb+");
    if (pFile == NULL)
    {
        return;
    }
    fwrite(inStr, sizeof(char), size, pFile);
    fclose(pFile);
}





int main(int argc, char* argv[])
{
	string filePath = "111.txt";

	char* buf = NULL;
	int size  = 0;

	ReadFromFile(filePath,buf,size);




	string encode;
	Base64_Encode(encode,(const unsigned char*)buf,size);



	unsigned char* decode = new unsigned char[size+1024];
	int decodeSize = 0;
	Base64_Decode(encode,decode,decodeSize);

	WriteToFile("111_bak.txt",buf,size);


	



	return 0;
}

