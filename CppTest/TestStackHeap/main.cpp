#include <iostream>

/*
1、栈在堆上面，栈的地址减少，堆的地址增加。
2、方法的参数在栈上，参数是从右向左入栈，为什么？
	主要是为了解决可变参数的问题，从右向左入栈，栈顶是第一个参数,
	而第一个参数，指出了参数个数，或者推断出参数个数（printf 的格式化字符串）。
	从栈顶开始，可以遍历这些参数。
3、pa本身也分配在栈上，pa的地址比a的地址小，pa的内容是a的地址
4、ppa本身也分配在栈上，ppa的地址比pa的地址小，ppa的内容是pa的地址
5、栈上数组tmp，相当于在栈上切出8个字节，tmp指向栈顶，地址最小，从栈顶向高地址
	有8个字节，拷贝"abcdef"（7个字节，包含NULL）到这8个字节中，a在栈顶，地址最小
*/
void Test(int a, int b)
{
	int* pa = &a;

	int** ppa = &pa;

	char tmp[8] = "abcdef";
}


int main(int argc, char* argv[])
{
	Test(1,17);
	getchar();
	return 0;
}

