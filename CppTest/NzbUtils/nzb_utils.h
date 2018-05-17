#ifndef NZB_UTILS_H_
#define NZB_UTILS_H_

#include <string>
#include <vector>
#include <list>
#include <algorithm>
#include <math.h>


using namespace std;

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

class NzbUtils
{
public:
	static void StringSplit(const std::string& str,const std::string& delim,
		std::vector<std::string>& strVec,bool isRemoveEmpty);

	// 用bbb替换aaa
	static void StringReplace(std::string& str,const std::string& aaa,
		const std::string& bbb);

	static bool IsContainsPrefix(const std::string& str,const std::string& prefix);

	static int GetOnlineTime(list<StatusTime>& staList);

	static list<StatusTime>::iterator GetIter(list<StatusTime>& staList,list<StatusTime>::iterator curIter,int status);

	// 0 .1+0 .2 不等于0 .3，下面就是解决这个问题，使用string表示加数，返回的和也是string
	static string GetRightDouble(std::string a, std::string b);

	static string GetNowTimeAsString();

	static string GetTimeStr(int unixTimeStamp);

	static int GetUnixTimeStamp(const string& timeStr);

	// 给出一个日期，获取起始时间
	static string GetStartTimeByDate(const string& date);

	// 根据时间秒数，获取时间字符串
	static string GetTimeStr_ByTimeInt(time_t timeInt);

	// 根据时间字符串，获取时间秒数
	static time_t GetTimeInt_ByTimeStr(const string& timeStr);

	static bool IsContainsSubStr(const string& str,const string& subStr);

};

#endif