// Test.cpp : �������̨Ӧ�ó������ڵ㡣
//

//#include "PersonLib.h"
#include "PersonDll.h"

#include "stdlib.h"

/*
	���Գ�����Test��lib1��lib2��dll1��dll2
	��Ϊ�������������
	1��Test->lib1->lib2
	   lib1�����Լ��Ĵ��룬��lib2�Ĳ��֣�ֻ��Ҫlib2��ͷ�ļ�����lib2�Ĵ���ʵ�֣�ʹ��ռλ��������
	   ����Test���ӵ�ʱ�򣬰�lib1�Ĵ���ʵ�ְ����������ٵݹ飬��lib1�й���lib2�Ĵ���ʵ��Ҳ����������
	   ����Test��ʱ�򣬲�����Ҫlib1��lib2��
	   Ҳ����˵��lib2���ϲ���lib1�У��ȵ�exe��ʱ��һ��ϲ���exe�С�

	2��Test->lib1->dll2
	   lib1�����Լ��Ĵ��룬��dll2�Ĳ��֣�ֻ��Ҫdll2��ͷ�ļ�����dll2�Ĵ���ʵ�֣�ʹ��ռλ��������
	   ����Test���ӵ�ʱ�򣬰�lib1�Ĵ���ʵ�ְ������������ǣ�dll2�еĴ��벻����������
	   ����Test��ʱ�򣬲���Ҫlib1��������Ҫdll2������Ҫdll��lib�ļ���
	   Ҳ����˵��dll2���ϲ���lib1�У��ȵ�exe��ʱ�򣬰�lib1�ϲ���exe�С�

	3��Test->dll1->lib2
	   dll1�����Լ��Ĵ��룬��lib2�Ĳ��֣���Ҫlib2��ͷ�ļ���ʵ�֣���lib2����lib2�Ĵ���ʵ�ְ�����dll1��
	   ����Test���ӵ�ʱ��dll1�еĴ��벻��������,Ҳ������Ҫlib2��
	   �������������ԣ�����lib2������dll1������test��ɾ��lib2��ɾ��test.exe,������test��
	    ���Գɹ���˵������test.exe,���ӵ�ʱ�򣬸�������Ҫlib2��
		Ҳ����˵����̬��ᱻ���ӵ���̬�����exe�У����ǲ������ӵ�������lib�С�
	   ����Test��ʱ����Ҫdll1�����ǲ���Ҫlib2
	   Ҳ����˵��lib2�ϲ���dll1�У��ȵ�exe��ʱ�򣬲���Ҫ�ϲ�dll1������ʱ��Ҫdll1��

	4��Test->dll1->dll2
	   dll1�����Լ��Ĵ��룬��dll2�Ĳ��֣���Ҫdll2��ͷ�ļ���lib�ļ�����dll2�Ĵ���ʵ�֣�ʹ��ռλ��������
	   ����Test���ӵ�ʱ��Test��Ҫdll1��lib��dll1��Ҫdll2��lib�����Ǵ���ʵ�ֶ����������Test�С�
	   ����Test��ʱ����Ҫdll1��dll2������Ҫ���ǵ�lib��
	   Ҳ����˵��dll2���ϲ���dll1�У��ȵ�exe��ʱ�򣬶��߶�����Ҫ�ϲ�,����ʱ��Ҫ���ߡ�
*/



int main(int argc, char* argv[])
{
	//PersonLib personLib;
	//personLib.Say();

	PersonDll personDll;
	personDll.Say();


	system("pause");
}

