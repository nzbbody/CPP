#include <stdlib.h>
#include <stdio.h>


void cc()
{
	throw 1;
}

void bb()
{
	cc();
}

void aa()
{
	bb();
}


int main(int argc, char* argv[])
{
	try
	{
		aa();
	}
	catch (...)
	{
		int hh =0;
	}

	return 0;
}


/*
int main(int argc, char* argv[])
{
	// �������͵Ĵ�С
	printf("�������͵Ĵ�С��\n");
	printf("int[%d],int*[%d],long[%d],long long[%d]\n\n\n",
		sizeof(int),
		sizeof(int*),
		sizeof(long),
		sizeof(long long));


	int dd = 0x7fffffff;

	// ����printf
	printf("����printf��\n");
	printf("��ӡint\n");
	int i = 0x7fffffff;
	printf("d[%d],ld[%ld],lld[%lld]\n",
		i,
		i,
		i);

	printf("��ӡlong\n");
	long l = 0x7fffffff;
	printf("d[%d],ld[%ld],lld[%lld]\n",
		l,
		l,
		l);

	printf("��ӡlong long\n");
	long long ll = 0x7fffffffffffffff;
	printf("d[%d],ld[%ld],lld[%lld]\n",
		ll,
		ll,
		ll);

	time_t tt = 0x7fffffffffffffff;
	printf("��ӡtime_t\n");
	printf("d[%d],ld[%ld],lld[%lld]\n",
		tt,
		tt,
		tt);
	printf("\n\n\n");



#define bbb

#if defined (aaa) || defined (bbb)
	printf("aaa||bbb\n");
#elif defined ccc
	printf("ccc\n");
#else
	printf("ddd\n");
#endif



	

	system("pause");
	return 0;
}

*/
