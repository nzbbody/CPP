#ifndef OPT_FILE_H_
#define OPT_FILE_H_

#include <stdio.h>
#include <string>

using namespace std;

namespace OptFile
{
	void ReadFromFile(const string& filePath,string& outStr);
	void ReadFromFile_2(const string& filePath,string& outStr);


	void ReadFromFile_ByByte(const string& filePath,string& outStr);
	void WriteToFile(const string& filePath, const string& inStr);
	void WriteToFile_2(const string& filePath, const string& inStr);

	int  GetFieSize(const string& filePath);
}

#endif