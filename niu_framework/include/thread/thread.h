namespace niu
{
	typedef void* (*ThreadCallback) (void*);

	class Thread
	{
	public:
		Thread(ThreadCallback callBack,void* param);
	};
}