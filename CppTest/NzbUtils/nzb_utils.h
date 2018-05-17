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

	// ��bbb�滻aaa
	static void StringReplace(std::string& str,const std::string& aaa,
		const std::string& bbb);

	static bool IsContainsPrefix(const std::string& str,const std::string& prefix);

	static int GetOnlineTime(list<StatusTime>& staList);

	static list<StatusTime>::iterator GetIter(list<StatusTime>& staList,list<StatusTime>::iterator curIter,int status);

	// 0 .1+0 .2 ������0 .3��������ǽ��������⣬ʹ��string��ʾ���������صĺ�Ҳ��string
	static string GetRightDouble(std::string a, std::string b);

	static string GetNowTimeAsString();

	static string GetTimeStr(int unixTimeStamp);

	static int GetUnixTimeStamp(const string& timeStr);

	// ����һ�����ڣ���ȡ��ʼʱ��
	static string GetStartTimeByDate(const string& date);

	// ����ʱ����������ȡʱ���ַ���
	static string GetTimeStr_ByTimeInt(time_t timeInt);

	// ����ʱ���ַ�������ȡʱ������
	static time_t GetTimeInt_ByTimeStr(const string& timeStr);

	static bool IsContainsSubStr(const string& str,const string& subStr);

};

#endif