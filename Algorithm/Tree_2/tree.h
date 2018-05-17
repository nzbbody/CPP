#ifndef TREE_H_
#define TREE_H_

#include <stdlib.h>

namespace NiuTree
{
	struct TreeNode
	{
		int			_Value;
		TreeNode*   _Left;
		TreeNode*   _Right;

		TreeNode(int value):_Value(value),_Left(NULL),_Right(NULL)
		{

		}
	};

	void CreateTree(TreeNode*& root);

	void LevelOrder(TreeNode* root);

	void MirrorTree(TreeNode* node);
}


#endif