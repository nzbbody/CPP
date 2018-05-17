// CppUtils.cpp : Defines the entry point for the console application.
//
#include "CppUtils.h"

#include <algorithm>
#include <time.h>

using namespace std;




namespace Niuzb
{
	namespace CppUtils
	{
		void StringSplit(const string& str,const string& delim,vector<string>& strVec,bool isRemoveEmpty)
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
	
		string GetNowTimeAsString()
		{
			char buf[64] = {0};
			time_t now = time(NULL);
			strftime(buf, 64, "%Y-%m-%d %H:%M:%S",localtime(&now));
			return string(buf);
		}

		string IntToStr(int a)
		{
			char str[64] = {0};
			sprintf(str,"%d",a);
			return str;
		}

		int StrToInt(const string& str)
		{
			return atoi(str.c_str());
		}

		bool IsContainsSubStr(const std::string& str,const std::string& subStr)
		{
			return str.find(subStr,0) != string::npos;
		}

		bool IntToIpStr(int inInt,string& outIpStr)
		{
			char tmp[32] = {0};

			sprintf(tmp,"%d.%d.%d.%d",
				(inInt>>24)&0xFF,
				(inInt>>16)&0xFF,
				(inInt>>8)&0xFF,
				inInt&0xFF);

			outIpStr = tmp;

			return true;
		}

		bool IpStrToInt(int& outInt,const string& inIpStr)
		{
			vector<string> strVec;
			StringSplit(inIpStr,".",strVec,true);

			if(strVec.size() != 4)
			{
				return false;
			}

			int a0 = atoi(strVec[0].c_str()) << 24;
			int a1 = atoi(strVec[1].c_str()) << 16;
			int a2 = atoi(strVec[2].c_str()) << 8;
			int a3 = atoi(strVec[3].c_str());



			outInt = a0+ a1+ a2 + a3;

			return true;
		}

		// 把1-2-3 替换为中国-浙江-杭州
		void ReplacePath(const string& inStr,map<int,string>& mapName,string& outStr)
		{
			vector<string> vecStr;
			StringSplit(inStr,"-",vecStr,true);

			outStr = "";

			for(vector<string>::iterator iter = vecStr.begin();
				iter != vecStr.end();++iter)
			{
				outStr+= (mapName[atoi(iter->c_str())]+"-");
			}

			outStr.replace(outStr.size()-1,1,"");
		}

		int GetOnlineTime(list<StatusTime>& staList)
		{
			int onlineTime = 0;

			//list<StatusTime>::iterator on = staList.

			//while()
			//{

			//}

			return 1;
		}


		list<StatusTime>::iterator getIter(list<StatusTime>& staList,list<StatusTime>::iterator curIter,int status)
		{
			while(curIter != staList.end())
			{
				++curIter;

				if(curIter->_Status == status)
				{
					return curIter;
				}
			}
			return curIter;
		}

	}
}


