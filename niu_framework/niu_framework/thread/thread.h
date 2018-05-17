#ifndef NIU_THREAD_H_
#define NIU_THREAD_H_

#ifdef DLL_EXPORT
#define DLL_API __declspec(dllexport)
#else
#define DLL_API __declspec(dllimport)
#endif


namespace niu
{
	typedef void* (*ThreadCallback) (void*);

	class DLL_API Thread
	{
	public:
		Thread(ThreadCallback callBack,void* param);


	};
}

#endif