#include "node.h"

#include <windows.h>
#include <stack>
#include <list>

using namespace std;


void preOrder(Node* root)
{
	if(root != NULL)
	{
		printf("%d-",root->value);
		preOrder(root->left);
		preOrder(root->right);
	}
}

void inOrder(Node* root)
{
	if(root != NULL)
	{
		inOrder(root->left);
		printf("%d-",root->value);		
		inOrder(root->right);
	}
}

void postOrder(Node* root)
{
	if(root != NULL)
	{
		postOrder(root->left);
		postOrder(root->right);
		printf("%d-",root->value);		
	}
}


void preOrder_2(Node* root)
{
	stack<Node*> stk;
	Node* cur = root;

	while(stk.size() >0 || cur != NULL)
	{
		while(cur != NULL)
		{
			printf("%d-",cur->value);
			stk.push(cur);
			cur = cur->left;
		}

		if(stk.size() >0)
		{
			cur = stk.top();
			stk.pop();
			cur = cur->right;
		}
	}	
}


void inOrder_2(Node* root)
{
	stack<Node*> stk;
	Node* cur = root;

	while(stk.size() >0 || cur != NULL)
	{
		while(cur != NULL)
		{			
			stk.push(cur);
			cur = cur->left;
		}

		if(stk.size() >0)
		{
			cur = stk.top();
			printf("%d-",cur->value);
			stk.pop();
			cur = cur->right;
		}
	}	
}

void postOrder_2(Node* root,stack<Node*>& postStk)
{
	stack<Node*> stk;
	Node* cur = root;

	while(stk.size() >0 || cur != NULL)
	{
		while(cur != NULL)
		{			
			stk.push(cur);
			postStk.push(cur);
			cur = cur->right;
		}

		if(stk.size() >0)
		{
			cur = stk.top();
			stk.pop();
			cur = cur->left;
		}
	}	
}


void preOrder_3(Node* root,list<Node*>& nodeList)
{
	stack<Node*> stk;
	Node* cur = root;
	stk.push(cur);

	while(stk.size() >0)
	{
		cur = stk.top();
		nodeList.push_back(cur);
		stk.pop();

		if(cur->right != NULL)
		{
			stk.push(cur->right);
		}	

		if(cur->left != NULL)
		{
			stk.push(cur->left);
		}
	}	
}

void postOrder_3(Node* root,stack<Node*>& nodeStk)
{
	stack<Node*> stk;
	Node* cur = root;
	stk.push(cur);

	while(stk.size() >0)
	{
		cur = stk.top();
		nodeStk.push(cur);
		stk.pop();

		if(cur->left != NULL)
		{
			stk.push(cur->left);
		}

		if(cur->right != NULL)
		{
			stk.push(cur->right);
		}		
	}	
}

void levelOrder(Node* root)
{
	Node* cur = root;

	list<Node*> nList;
	nList.push_back(cur);

	while(nList.size() >0)
	{
		cur = nList.front();

		nList.pop_front();

		printf("%d-",cur->value);

		if(cur->left != NULL)
		{
			nList.push_back(cur->left);
		}

		if(cur->right != NULL)
		{
			nList.push_back(cur->right);
		}
	}	
}

void createTree(Node*& root)
{
	root = new Node(0);

	Node* n1 = new Node(1);
	Node* n2 = new Node(2);
	Node* n3 = new Node(3);
	Node* n4 = new Node(4);
	Node* n5 = new Node(5);
	Node* n6 = new Node(6);
	Node* n7 = new Node(7);
	Node* n8 = new Node(8);
	Node* n9 = new Node(9);
	Node* n10 = new Node(10);

	root->left = n1;
	root->right = n2;

	n1->left = n3;
	n1->right = n4;

	n2->left = n5;
	n2->right = n6;

	n3->left = n7;
	n3->right = n8;

	n4->right = n9;
	n5->left = n10;
}

void printStack(stack<Node*>& nodeStk)
{
	while(nodeStk.size() >0)
	{
		printf("%d-",nodeStk.top()->value);
		nodeStk.pop();
	}	
}

void printList(list<Node*>& nodeList)
{
	while(nodeList.size() >0)
	{
		printf("%d-",nodeList.front()->value);
		nodeList.pop_front();
	}	
}



int main(int argc, char* argv[])
{
	stack<Node*> nodeStk;
	list<Node*> nodeList;

	Node* root;
	createTree(root);

	preOrder(root);
	printf("\n");
	preOrder_2(root);
	printf("\n");
	preOrder_3(root,nodeList);
	printList(nodeList);
	printf("\n\n");

	inOrder(root);
	printf("\n");
	inOrder_2(root);
	printf("\n\n");

	postOrder(root);
	printf("\n");	
	postOrder_2(root,nodeStk);
	printStack(nodeStk);
	printf("\n");
	postOrder_3(root,nodeStk);
	printStack(nodeStk);
	printf("\n\n");


	levelOrder(root);
	printf("\n\n");
	system("pause");
	return 0;
}

