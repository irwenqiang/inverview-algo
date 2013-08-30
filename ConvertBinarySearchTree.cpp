#include <stdio.h>
#include "utils/BinaryTree.h"

void ConvertNode(BinaryTreeNode* pRootOfTree, BinaryTreeNode** pLastNodeInList);

BinaryTreeNode* Convert(BinaryTreeNode* pRootOfTree) {
	
	BinaryTreeNode* pLastNodeInList = NULL;
	ConvertNode(pRootOfTree, &pLastNodeInList);

	BinaryTreeNode* pHeadOfList = pLastNodeInList;

	while(pHeadOfList != NULL && pHeadOfList->m_pLeft != NULL)
		pHeadOfList = pHeadOfList->m_pLeft;
	
	return pHeadOfList;
}

void ConvertNode(BinaryTreeNode* pNode, BinaryTreeNode** pLastNodeInList) {

	if (pNode == NULL)
		return;
	
	BinaryTreeNode *pCurrent = pNode;

	if (pCurrent->m_pLeft != NULL)
		ConvertNode(pCurrent->m_pLeft, pLastNodeInList);

	pCurrent->m_pLeft = *pLastNodeInList;

	if(*pLastNodeInList != NULL)
		(*pLastNodeInList)->m_pRight =  pCurrent;
	
	*pLastNodeInList = pCurrent;

	if(pCurrent->m_pRight != NULL)
		ConvertNode(pCurrent->m_pRight, pLastNodeInList);

}

void PrintDoubleLinkedList(BinaryTreeNode* pHeadOfList)
{
	BinaryTreeNode* pNode = pHeadOfList;

	printf("The nodes from left to right are:\n");
	while(pNode != NULL)
	{
		printf("%d\t", pNode->m_nValue);

		if(pNode->m_pRight == NULL)
			break;
		pNode = pNode->m_pRight;
	}

	printf("\nThe nodes from right to left are:\n");
	while(pNode != NULL)
	{
		printf("%d\t", pNode->m_nValue);

		if(pNode->m_pLeft == NULL)
			break;
		pNode = pNode->m_pLeft;
	}

	printf("\n");
}

void DestroyList(BinaryTreeNode* pHeadOfList)
{
	BinaryTreeNode* pNode = pHeadOfList;
	while(pNode != NULL)
	{
		BinaryTreeNode* pNext = pNode->m_pRight;

		delete pNode;
		pNode = pNext;
	}
}

int main() {

	BinaryTreeNode* pNode10 = CreateBinaryTreeNode(10);
	BinaryTreeNode* pNode6 = CreateBinaryTreeNode(6);
	BinaryTreeNode* pNode14 = CreateBinaryTreeNode(14);
	BinaryTreeNode* pNode4 = CreateBinaryTreeNode(4);
	BinaryTreeNode* pNode8 = CreateBinaryTreeNode(8);
	BinaryTreeNode* pNode12 = CreateBinaryTreeNode(12);
	BinaryTreeNode* pNode16 = CreateBinaryTreeNode(16);

	ConnectTreeNodes(pNode10, pNode6, pNode14);
	ConnectTreeNodes(pNode6, pNode4, pNode8);
	ConnectTreeNodes(pNode14, pNode12, pNode16);
	
	PrintTree(pNode10);

	printf("foo\n");

	BinaryTreeNode* pNode = (Convert(pNode10));	

	PrintDoubleLinkedList(pNode);

	
    	DestroyList(pNode4);

	return 0;
}
