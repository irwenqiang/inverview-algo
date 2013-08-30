#include <stdio.h>
#include "utils/BinaryTree.h"

BinaryTreeNode* ConstructBinaryTree(int *startPreorder, int *endPreorder, int *startInorder, int *endInorder) {
	
	int rootValue = startPreorder[0];
	BinaryTreeNode *root = new BinaryTreeNode();
	root->m_nValue = rootValue;
	root->m_pLeft = root->m_pRight = NULL;

	if (startPreorder == endPreorder) {
		if (startInorder == endInorder && *startInorder == *endInorder) 
			return root;
		else
			return NULL;
	}

	int *rootInorder = startInorder;

	while(rootInorder <= endInorder && *rootInorder != rootValue)
		rootInorder++;
	
	if(rootInorder == endInorder && *rootInorder != rootValue)
		return NULL;
	
	int leftLength = rootInorder - startInorder;
	int* leftPreorderEnd = startPreorder + leftLength;

	if (leftLength > 0)
		root->m_pLeft = ConstructBinaryTree(startPreorder + 1, leftPreorderEnd, startInorder, rootInorder-1);

	if (leftLength < endPreorder - startPreorder) 
		root->m_pRight = ConstructBinaryTree(leftPreorderEnd + 1, endPreorder, rootInorder + 1, endInorder);

	
	return root;
}

int main() {
	const int length = 8;

	int preorder[length] = {1,2,4,7,3,5,6,8};
	int inorder[length] = {4,7,2,1,5,3,8,6};

	BinaryTreeNode *tree = ConstructBinaryTree(preorder, preorder + length - 1, inorder, inorder + length -1);

	PrintTree(tree);

	DestroyTree(tree);
}
