#ifndef STRINGUTIL_H_
#define STRINGUTIL_H_

#include <string>
#include <vector>
using namespace std;

bool IsMatchPrefix(const string& str,const string& prefix);

bool IsContainsSubStr(const string& str,const string& subStr);

void StringReplace(string& str,const string& aaa,const string& bbb);

void StringSplit(const string& str,const string& delim,vector<string>& strVec,bool isRemoveEmpty);

void RemoveLastElement(string& str);

#endif