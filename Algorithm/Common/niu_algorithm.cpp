#include "niu_algorithm.h"
#include <algorithm>

/*
	算法找出增删改的记录，考虑老的集合为a,b,c，新的集合为b,c,d,得出的结果是：删除a,修改b,c,增加d 
*/
void NiuAlgorithm::GetOptVec(vector<Student>& oldVec,vector<Student>& newVec,vector<Student>& optVec)
{
	// 遍历oldVec，newVec找不到是删除，找到了是修改
	for(vector<Student>::iterator iter = oldVec.begin();iter != oldVec.end();++iter)
	{
		vector<Student>::iterator itq = find(newVec.begin(),newVec.end(),*iter);

		if(itq == newVec.end())
		{
			Student st = *iter;
			st._Opt = Opt_Del;
			optVec.push_back(st);
		}
		else
		{
			Student st = *itq;
			st._Opt = Opt_Mod;
			optVec.push_back(st);
		}
	}

	// 遍历newVec，oldVec找不到是增加
	for(vector<Student>::iterator iter = newVec.begin();iter != newVec.end();++iter)
	{
		vector<Student>::iterator itq = find(oldVec.begin(),oldVec.end(),*iter);

		if(itq == oldVec.end())
		{
			Student st = *iter;
			st._Opt = Opt_Add;
			optVec.push_back(st);
		}
	}
}