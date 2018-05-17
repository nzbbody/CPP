#ifndef NODE_H_
#define NODE_H_

#include <stdio.h>

struct Node
{
	int value;
	Node* left;
	Node* right;

	Node(int val):value(val),left(NULL),right(NULL)
	{

	}	
};

#endif