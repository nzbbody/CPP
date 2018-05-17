#ifndef CPPUTILS_H_
#define CPPUTILS_H_

#ifdef DLL_FILE
#define DLL_API __declspec(dllexport)
#else
#define DLL_API __declspec(dllimport)
#endif

#include <string>
#include <vector>
#include <map>
#include <list>


struct StatusTime
{
	int _Status;
	int _Time;

	StatusTime()
	{
		_Status = 1;
		_Time   = 0;
	}

	StatusTime(int status,int time)
	{
		_Status = status;
		_Time   = time;
	}
};



namespace Niuzb
{
	namespace CppUtils
	{
		DLL_API void StringSplit(const std::string& str,const std::string& delim,
			std::vector<std::string>& strVec,bool isRemoveEmpty);

		DLL_API std::string GetNowTimeAsString();

		DLL_API std::string IntToStr(int a);

		DLL_API int StrToInt(const std::string& str);

		DLL_API bool IsContainsSubStr(const std::string& str,const std::string& subStr);

		DLL_API bool IntToIpStr(int inInt,std::string& outIpStr);

		DLL_API bool IpStrToInt(int& outInt,const std::string& inIpStr);

		DLL_API void ReplacePath(const std::string& inStr,std::map<int,std::string>& mapName,std::string& outStr);
	
		DLL_API int GetOnlineTime(std::list<StatusTime>& staList);

		DLL_API std::list<StatusTime>::iterator getIter(std::list<StatusTime>& staList,std::list<StatusTime>::iterator curIter,int status);
	}
}








#endif