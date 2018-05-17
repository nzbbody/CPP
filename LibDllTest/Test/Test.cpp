// Test.cpp : 定义控制台应用程序的入口点。
//

//#include "PersonLib.h"
#include "PersonDll.h"

#include "stdlib.h"

/*
	测试场景，Test，lib1，lib2，dll1，dll2
	分为下面四种情况：
	1、Test->lib1->lib2
	   lib1编译自己的代码，对lib2的部分，只需要lib2的头文件，对lib2的代码实现，使用占位符关联。
	   生成Test连接的时候，把lib1的代码实现包含进来，再递归，把lib1中关联lib2的代码实现也包含进来。
	   运行Test的时候，不再需要lib1和lib2。
	   也就是说，lib2不合并到lib1中，等到exe的时候，一起合并到exe中。

	2、Test->lib1->dll2
	   lib1编译自己的代码，对dll2的部分，只需要dll2的头文件，对dll2的代码实现，使用占位符关联。
	   生成Test连接的时候，把lib1的代码实现包含进来，但是，dll2中的代码不包含进来。
	   运行Test的时候，不需要lib1，但是需要dll2【不需要dll的lib文件】
	   也就是说，dll2不合并到lib1中，等到exe的时候，把lib1合并到exe中。

	3、Test->dll1->lib2
	   dll1编译自己的代码，对lib2的部分，需要lib2的头文件和实现，即lib2，把lib2的代码实现包含到dll1中
	   生成Test连接的时候，dll1中的代码不包含进来,也不再需要lib2。
	   【可以这样测试，生成lib2，生成dll1，生成test，删除lib2，删除test.exe,再生成test，
	    可以成功，说明生成test.exe,连接的时候，根本不需要lib2，
		也就是说，静态库会被连接到动态库或者exe中，但是不会连接到其他的lib中】
	   运行Test的时候，需要dll1，但是不需要lib2
	   也就是说，lib2合并到dll1中，等到exe的时候，不需要合并dll1，运行时需要dll1。

	4、Test->dll1->dll2
	   dll1编译自己的代码，对dll2的部分，需要dll2的头文件和lib文件，对dll2的代码实现，使用占位符关联。
	   生成Test连接的时候，Test需要dll1的lib，dll1需要dll2的lib，但是代码实现都不会包含在Test中。
	   运行Test的时候，需要dll1和dll2【不需要他们的lib】
	   也就是说，dll2不合并到dll1中，等到exe的时候，二者都不需要合并,运行时需要二者。
*/



int main(int argc, char* argv[])
{
	//PersonLib personLib;
	//personLib.Say();

	PersonDll personDll;
	personDll.Say();


	system("pause");
}

