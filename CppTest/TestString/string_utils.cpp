#include "string_utils.h"
#include <algorithm>

// �Ƿ�ƥ��ǰ׺
bool IsMatchPrefix(const string& str,const string& prefix)
{
	return strncmp(str.c_str(),prefix.c_str(),prefix.size()) == 0;
}

// �Ƿ�����ַ���
bool IsContainsSubStr(const string& str,const string& subStr)
{
	return str.find(subStr,0) != string::npos;
}

// ��bbb�滻aaa
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

// ʹ��delim��Ϊ�ָ���
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

// ɾ�����һ��Ԫ��
// ע�⣺����vector��list��ɾ�����һ��Ԫ�أ�ֻ��ʹ��
// erase(������) �� resize(size-1)
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
	// ʹ���һ���ַ���Ч���ﵽɾ�����һ���ַ���Ŀ��
	// �������ַ�ʽ�����⣬��Ϊsrc��sizeû�б仯
	//str[str.size()-1]=0;
}

