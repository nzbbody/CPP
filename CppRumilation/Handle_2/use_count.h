#ifndef USE_COUNT_H_
#define USE_COUNT_H_

class UseCount
{
public:
	UseCount():_p(new int(1)){}
	UseCount(const UseCount& rhs)
	{
		addRef(rhs);
	}

	UseCount& operator=(const UseCount& rhs)
	{
		if(this != &rhs)
		{
			subRef();
			addRef(rhs);
		}
		return *this;
	}

	~UseCount()
	{
		subRef();
	}

	bool IsOnly()
	{
		return (*_p == 1);
	}

	void MakeOnly()
	{
		if(IsOnly()) // 防止已经是only，用户还调用MakeOnly
		{
			return;
		}
		--*_p;
		_p = new int(1);
	}

private:
	void addRef(const UseCount& rhs)
	{
		_p = rhs._p;
		++*_p;
	}

	void subRef()
	{
		if(--*_p == 0)
		{
			delete _p;
		}
	}

private:
	int* _p;
};

#endif