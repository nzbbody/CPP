#include "PersonLib.h"

/*
	��������������test.exe ����a.lib(��̬��)��a.lib����b.lib(��̬��)
	����test.exe��ʱ����Ҫ����a.lib��b.lib��Ϊʲô��

	��ǰ��Ϊ������a.lib��ʱ�򣬻��b.lib�ϲ���a.lib�У������Ļ������������test.exe��ʱ��
	�Ͳ�����Ҫb.lib�ˡ�
	��ʵ�ϲ��������ģ�����a.libֻ��Ҫb��ͷ�ļ�������Ҫb.lib�����ɵ�a.libֻ��a��o�ļ��ļ��ϡ�
	
	�ڱ���test.exe��ʱ�򣬲Ű����е�lib�ļ�������ȥ��
	Ҳ����˵��lib�ļ���exe�ļ�������ȥ������lib�ļ���������������lib�ļ���	
*/
void PersonLib::Say()
{
	printf("I am PersonLib\n");
	dog.Say();
}