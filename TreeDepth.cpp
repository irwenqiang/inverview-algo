#include <stdio.h>
#include "utils/BinaryTree.h"

int TreeDepth(BinaryTreeNode* pRoot) {
	if (pRoot != NULL) {
		int left = TreeDepth(pRoot->m_pLeft);
		int right = TreeDepth(pRoot->m_pRight);

		return (left > right) ? left+1 : right + 1;
	}
}


int main() {
	BinaryTreeNode* pNode1 = CreateBinaryTreeNode(1);
	BinaryTreeNode* pNode2 = CreateBinaryTreeNode(2);
	BinaryTreeNode* pNode3 = CreateBinaryTreeNode(3);
	BinaryTreeNode* pNode4 = CreateBinaryTreeNode(4);
	BinaryTreeNode* pNode5 = CreateBinaryTreeNode(5);
	BinaryTreeNode* pNode6 = CreateBinaryTreeNode(6);
	BinaryTreeNode* pNode7 = CreateBinaryTreeNode(7);

	ConnectTreeNodes(pNode1, pNode2, pNode3);
	ConnectTreeNodes(pNode2, pNode4, pNode5);
	ConnectTreeNodes(pNode3, NULL, pNode6);
	ConnectTreeNodes(pNode5, pNode7, NULL);

	int depth = TreeDepth(pNode1);
	
	printf("%d\n", depth);


	return 0;
}
