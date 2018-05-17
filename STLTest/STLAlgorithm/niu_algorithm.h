#ifndef ALGORITHM_H_
#define ALGORITHM_H_

template <typename Iterator,typename T>
Iterator Niu_Remove(Iterator first,Iterator last,const T& value)
{
	Iterator result = first;
	while(first != last)
	{
		if(*first != value)
		{
			*result++ = *first;
		}
		++first;
	}

	return result;
}

// 序列[fist1,last1)是否包含前缀[fist2,last2)
template <typename Iterator>
bool Niu_IsContainsPrefix(Iterator first1,Iterator last1,Iterator first2,Iterator last2)
{
	while(first1 != last1 && first2 != last2)
	{
		if(*first1 != *first2)
		{
			break;
		}
		++first1;
		++first2;
	}

	if(first2 == last2)
	{
		return true;
	}
	return false;
}

// 从序列[fist1,last1)中查找子序列[fist2,last2)
template <typename Iterator>
Iterator Niu_Search(Iterator first1,Iterator last1,Iterator first2,Iterator last2)
{
	while(first1 != last1)
	{
		if(Niu_IsContainsPrefix(first1,last1,first2,last2))
		{
			return first1;
		}
		++first1;		
	}
	return first1;
}

#endif