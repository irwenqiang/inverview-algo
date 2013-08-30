#include "BinaryTree.h"
#include <stdio.h>

BinaryTreeNode* CreateBinaryTreeNode(int value) {
	BinaryTreeNode* pNode = new BinaryTreeNode();
	pNode->m_nValue = value;
	pNode->m_pLeft = NULL;
	pNode->m_pRight = NULL;

	return pNode;
}

void ConnectTreeNodes(BinaryTreeNode* pParent, BinaryTreeNode* pLeft, BinaryTreeNode* pRight) {

	if (pParent != NULL) {
		pParent->m_pLeft = pLeft;
		pParent->m_pRight = pRight;
	}
}

void PrintTreeNode(BinaryTreeNode* pNode) {
	if (pNode != NULL) {
		printf("%d\n", pNode->m_nValue);

		if (pNode->m_pLeft != NULL)
			printf("%d\n", pNode->m_pLeft->m_nValue);

		if (pNode->m_pRight != NULL)
			printf("%d\n", pNode->m_pRight->m_nValue);
	}
}


void PrintTree(BinaryTreeNode* pRoot) {
	if (pRoot != NULL) {
		PrintTreeNode(pRoot);
		if(pRoot->m_pLeft != NULL) 
			PrintTree(pRoot->m_pLeft);
		if(pRoot->m_pRight != NULL)
			PrintTree(pRoot->m_pRight);
	}
}

void DestroyTree(BinaryTreeNode* pRoot) {
	
	if(pRoot != NULL) {
		BinaryTreeNode* pLeft = pRoot->m_pLeft;
		BinaryTreeNode* pRight = pRoot->m_pRight;

		delete pRoot;
		pRoot = NULL;

		DestroyTree(pLeft);
		DestroyTree(pRight);
	}
}
