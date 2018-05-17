#include "tree.h"
#include <stdio.h>

using namespace NiuTree;

int main(int argc, char* argv[])
{
	TreeNode* root;

	CreateTree(root);
	LevelOrder(root);

	MirrorTree(root);
	LevelOrder(root);
	
	getchar();

	return 0;
}

