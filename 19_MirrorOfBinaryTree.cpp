#include <stdio.h>
#include "utils/BinaryTree.h"


void MirrorRecursively(BinaryTreeNode *pNode) {

	if(pNode == NULL ||(pNode->m_pLeft == NULL && pNode->m_pRight == NULL)) 
		return;

	BinaryTreeNode* tmp = pNode->m_pLeft;
	pNode->m_pLeft = pNode->m_pRight;
	pNode->m_pRight = tmp;

	MirrorRecursively(pNode->m_pLeft);
	MirrorRecursively(pNode->m_pRight);
		

}
int main() {

	BinaryTreeNode* pNode8 = CreateBinaryTreeNode(8);
	BinaryTreeNode* pNode6 = CreateBinaryTreeNode(6);
	BinaryTreeNode* pNode10 = CreateBinaryTreeNode(10);
	BinaryTreeNode* pNode5 = CreateBinaryTreeNode(5);
	BinaryTreeNode* pNode7 = CreateBinaryTreeNode(7);
	BinaryTreeNode* pNode9 = CreateBinaryTreeNode(9);
	BinaryTreeNode* pNode11 = CreateBinaryTreeNode(11);

	ConnectTreeNodes(pNode8, pNode6, pNode10);
	ConnectTreeNodes(pNode6, pNode5, pNode7);
	ConnectTreeNodes(pNode10, pNode9, pNode11);

	PrintTree(pNode8);

	MirrorRecursively(pNode8);

	PrintTree(pNode8);
	return 0;
}
