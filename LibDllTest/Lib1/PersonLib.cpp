#include "PersonLib.h"

/*
	考虑下面的情况：test.exe 引用a.lib(静态库)，a.lib引用b.lib(静态库)
	编译test.exe的时候，需要引用a.lib和b.lib，为什么？

	以前以为：编译a.lib的时候，会把b.lib合并到a.lib中，这样的话，按道理编译test.exe的时候，
	就不再需要b.lib了。
	事实上不是这样的，编译a.lib只需要b的头文件，不需要b.lib，生成的a.lib只是a中o文件的集合。
	
	在编译test.exe的时候，才把所有的lib文件包含进去。
	也就是说，lib文件被exe文件包含进去，但是lib文件并不包含其他的lib文件。	
*/
void PersonLib::Say()
{
	printf("I am PersonLib\n");
	dog.Say();
}