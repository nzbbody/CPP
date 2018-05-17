#include "tree.h"
#include <list>


namespace NiuTree
{
	using namespace std;

	void CreateTree(TreeNode*& root)
	{
		root = new TreeNode(0);

		TreeNode* n1 = new TreeNode(1);
		TreeNode* n2 = new TreeNode(2);
		TreeNode* n3 = new TreeNode(3);
		TreeNode* n4 = new TreeNode(4);
		TreeNode* n5 = new TreeNode(5);
		TreeNode* n6 = new TreeNode(6);
		TreeNode* n7 = new TreeNode(7);
		TreeNode* n8 = new TreeNode(8);
		TreeNode* n9 = new TreeNode(9);
		TreeNode* n10 = new TreeNode(10);

		root->_Left = n1;
		root->_Right = n2;

		n1->_Left = n3;
		n1->_Right = n4;

		n2->_Left = n5;
		n2->_Right = n6;

		n3->_Left = n7;
		n3->_Right = n8;

		n4->_Right = n9;
		n5->_Left = n10;
	}

	void LevelOrder(TreeNode* root)
	{
		TreeNode* cur = root;

		list<TreeNode*> nList;
		nList.push_back(cur);

		while(nList.size() >0)
		{
			cur = nList.front();

			nList.pop_front();

			printf("%d-",cur->_Value);

			if(cur->_Left != NULL)
			{
				nList.push_back(cur->_Left);
			}

			if(cur->_Right != NULL)
			{
				nList.push_back(cur->_Right);
			}
		}
		printf("\n");
	}


	void MirrorTree(TreeNode* node)
	{
		if(node == NULL)
		{
			return;
		}

		if(node->_Left != NULL)
		{
			if(node->_Right != NULL) // 有两个孩子
			{
				TreeNode* tmp = node->_Left;
				node->_Left = node->_Right;
				node->_Right = tmp;
			}
			else // 只有左孩子
			{
				node->_Right = node->_Left;
				node->_Left = NULL;
			}
		}
		else
		{
			if(node->_Right != NULL) // 只有右孩子
			{
				node->_Left = node->_Right;
				node->_Right = NULL;
			}
			else // 没有孩子
			{
				// do nothing
			}
		}

		MirrorTree(node->_Left);
		MirrorTree(node->_Right);
	}
}