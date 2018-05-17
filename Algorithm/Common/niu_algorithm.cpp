#include "niu_algorithm.h"
#include <algorithm>

/*
	�㷨�ҳ���ɾ�ĵļ�¼�������ϵļ���Ϊa,b,c���µļ���Ϊb,c,d,�ó��Ľ���ǣ�ɾ��a,�޸�b,c,����d 
*/
void NiuAlgorithm::GetOptVec(vector<Student>& oldVec,vector<Student>& newVec,vector<Student>& optVec)
{
	// ����oldVec��newVec�Ҳ�����ɾ�����ҵ������޸�
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

	// ����newVec��oldVec�Ҳ���������
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