
/**
 * Copyright (C) 2012 ZHEJIANG  DAHUA  SYSTEM ENGINEERING  CO., LTD 
 */
 

#ifndef _LIST_I_H
#define _LIST_I_H


#include <list>

template <class T>
class listI : public std::list<T>
{
};

#include <queue>

template <class T>
class queueI : public std::queue<T> 
{
};

#include <vector>
template <class T>
class vectorI : public std::vector<T> 
{
};

#endif

