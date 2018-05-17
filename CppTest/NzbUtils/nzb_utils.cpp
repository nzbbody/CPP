#include "nzb_utils.h"
#include <time.h>


void NzbUtils::StringSplit(const string& str,const string& delim,
						   vector<string>& strVec,bool isRemoveEmpty)
{
	size_t begin = 0;
	size_t end = str.find(delim,begin);

	while(end!=string::npos)
	{
		strVec.push_back(str.substr(begin,end-begin));
		begin = end+strlen(delim.c_str());
		end = str.find(delim,begin);
	}

	if(end>begin)
	{
		strVec.push_back(str.substr(begin,end-begin));
	}

	if(isRemoveEmpty)
	{
		strVec.erase(remove(strVec.begin(),strVec.end(),""),strVec.end());
	}
}

void NzbUtils::StringReplace(string& str,const string& aaa,const string& bbb)
{
	size_t pos = 0;
	size_t aSize = aaa.size();
	size_t bSize = bbb.size();

	while((pos = str.find(aaa,pos)) != string::npos)
	{
		str.replace(pos,aSize,bbb);
		pos+=bSize;
	}
}


bool NzbUtils::IsContainsPrefix(const std::string& str,const std::string& prefix)
{
	return strncmp(str.c_str(),prefix.c_str(),prefix.size()) == 0;
}



int NzbUtils::GetOnlineTime(list<StatusTime>& staList)
{
	int totalTime = 0;

	list<StatusTime>::iterator on = GetIter(staList,staList.begin(),1);
	list<StatusTime>::iterator off = GetIter(staList,on,2);

	while(on!=staList.end() && off!=staList.end())
	{
		totalTime +=(off->_Time - on->_Time);
		on = GetIter(staList,off,1);
		off = GetIter(staList,on,2);
	}

	return totalTime;
}


list<StatusTime>::iterator NzbUtils::GetIter(list<StatusTime>& staList,list<StatusTime>::iterator curIter,int status)
{
	while(curIter != staList.end())
	{
		if(curIter->_Status == status)
		{
			return curIter;
		}
		
		++curIter;		
	}

	return curIter;
}


string NzbUtils::GetRightDouble(string a, string b)
{
	vector<string> aVec;
	StringSplit(a,".",aVec,true);
	
	vector<string> bVec;
	StringSplit(b,".",bVec,true);

	int c1 =  atoi(aVec[0].c_str()) + atoi(bVec[0].c_str());

	int maxLen = aVec[1].size() > bVec[1].size() ? aVec[1].size():bVec[1].size();
	if(maxLen > aVec[1].size())
	{
		while(maxLen > aVec[1].size())
		{
			aVec[1]+="0";
		}
	}

	if(maxLen > bVec[1].size())
	{
		while(maxLen > bVec[1].size())
		{
			bVec[1]+="0";
		}
	}

	int c2 =  atoi(aVec[1].c_str()) + atoi(bVec[1].c_str());

	char ch[64] = {0};
	sprintf(ch,"%d",c2);

	if(strlen(ch) > aVec[1].size())
	{
		c2 = atoi(ch+1);
		c1 = c1+1;		
	}

	char ret[64] = {0};

	sprintf(ret,"%d.%d",c1,c2);

	return ret;
}


string NzbUtils::GetNowTimeAsString()
{
	char buf[64] = {0};
	time_t now = time(NULL);
	//方法1：
	/*tm* ptm = localtime(&now);
	sprintf(buf, "%04d-%02d-%02d %02d:%02d:%02d", 
		ptm->tm_year+1900, 
		ptm->tm_mon+1, 
		ptm->tm_mday,
		ptm->tm_hour,
		ptm->tm_min, 
		ptm->tm_sec);*/

	//方法2：
	strftime(buf, 64, "%Y-%m-%d %H:%M:%S",localtime(&now));
	return buf;
}

// 由1473142696 得到 "2016-09-06 14:18:16"
string NzbUtils::GetTimeStr(int unixTimeStamp)
{
	char buf[64] = {0};
	time_t now = (time_t)(unixTimeStamp);
	//方法1：
	tm* ptm = localtime(&now);
	sprintf(buf, "%04d-%02d-%02d %02d:%02d:%02d", 
		ptm->tm_year+1900, 
		ptm->tm_mon+1, 
		ptm->tm_mday,
		ptm->tm_hour,
		ptm->tm_min, 
		ptm->tm_sec);

	//方法2：
	//strftime(buf, 64, "%Y-%m-%d %H:%M:%S",localtime(&now));
	return buf;
}

// 由"2016-09-06 14:18:16" 得到 1473142696
int NzbUtils::GetUnixTimeStamp(const string& timeStr)
{
	char year[5] = {0};
	char month[3] = {0};
	char day[3] = {0};
	char hour[3] = {0};
	char min[3] = {0};
	char sec[3] = {0};

	if(sscanf(timeStr.c_str(), "%4c-%2c-%2c %2c:%2c:%2c", year,month,day,hour,min,sec) != 6)
	{
		return -1;
	}

	struct tm tmLocal = {0};
	tmLocal.tm_year = atoi(year) - 1900;
	tmLocal.tm_mon = atoi(month) -1;
	tmLocal.tm_mday = atoi(day);
	tmLocal.tm_hour = atoi(hour);
	tmLocal.tm_min = atoi(min);
	tmLocal.tm_sec = atoi(sec);

	return (int)mktime(&tmLocal);
}


string NzbUtils::GetStartTimeByDate(const string& date)
{
	char time[64]={0};
	sprintf(time,"%s 0:0:0",date.c_str());
	return time;
}


string NzbUtils::GetTimeStr_ByTimeInt(time_t timeInt)
{
	tm* ptm = localtime(&timeInt);	
	char timeStr[64]={0};

	sprintf(timeStr,"%d-%d-%d %d:%d:%d",
		ptm->tm_year+1900,
		ptm->tm_mon+1, 
		ptm->tm_mday,
		ptm->tm_hour,
		ptm->tm_min, 
		ptm->tm_sec);
	
	return timeStr;
}

time_t NzbUtils::GetTimeInt_ByTimeStr(const string& timeStr)
{
	string timeStrCpy(timeStr);
	StringReplace(timeStrCpy,":","-");
	StringReplace(timeStrCpy," ","-");

	vector<string> vecStr;
	StringSplit(timeStrCpy,"-",vecStr,true);

	struct tm stTime;
	stTime.tm_year = atoi(vecStr[0].c_str()) -1900;
	stTime.tm_mon = atoi(vecStr[1].c_str()) -1;
	stTime.tm_mday = atoi(vecStr[2].c_str());
	stTime.tm_hour = atoi(vecStr[3].c_str());
	stTime.tm_min = atoi(vecStr[4].c_str());
	stTime.tm_sec = atoi(vecStr[5].c_str());

	return mktime(&stTime);
}

bool NzbUtils::IsContainsSubStr(const string& str,const string& subStr)
{
	return str.find(subStr,0) != string::npos;
}