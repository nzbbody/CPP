#include "string_utils.h"
#include <algorithm>

// 是否匹配前缀
bool IsMatchPrefix(const string& str,const string& prefix)
{
	return strncmp(str.c_str(),prefix.c_str(),prefix.size()) == 0;
}

// 是否包含字符串
bool IsContainsSubStr(const string& str,const string& subStr)
{
	return str.find(subStr,0) != string::npos;
}

// 用bbb替换aaa
void StringReplace(string& str,const string& aaa,const string& bbb)
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

// 使用delim作为分隔符
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

// 删除最后一个元素
// 注意：对于vector和list，删除最后一个元素，只能使用
// erase(迭代器) 和 resize(size-1)
void RemoveLastElement(string& str)
{
	if(str.size() == 0)
	{
		return;
	}

	//str = str.substr(0,str.size()-1);
	//str.erase(str.size()-1);
	//str.erase(--str.end());
	str.resize(str.size()-1);
	// 使最后一个字符无效，达到删除最后一个字符的目的
	// 但是这种方式有问题，因为src的size没有变化
	//str[str.size()-1]=0;
}

