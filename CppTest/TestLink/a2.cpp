#include "a.h"
#include <stdio.h>
void a2_print()
{
	printf("before a2.cpp a[%d]\n",a);
	a = 102;
	printf("after a2.cpp a[%d]\n",a);
}