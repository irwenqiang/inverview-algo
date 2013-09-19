#include <stdio.h>
#include "utils/BinaryTree.h"

bool HasSubtreeCore(BinaryTreeNode* pRoot1, BinaryTreeNode* pRoot2);
bool DoesTree1HaveTree2(BinaryTreeNode* pRoot1, BinaryTreeNode* pRoot2);

bool HasSubtreeCore(BinaryTreeNode* pRoot1, BinaryTreeNode* pRoot2) {
	bool result = false;

	if (pRoot1 != NULL && pRoot2 != NULL) {
		if (pRoot1->m_nValue == pRoot2->m_nValue) 
			result = DoesTree1HaveTree2(pRoot1, pRoot2);
		if (!result)
			HasSubtreeCore(pRoot1->m_pLeft, pRoot2);
		if (!result)
			HasSubtreeCore(pRoot1->m_pRight, pRoot2);
	}

	return result;
}

bool DoesTree1HaveTree2(BinaryTreeNode* pRoot1, BinaryTreeNode* pRoot2) {

	if (pRoot2 == NULL)
		return true;
	if (pRoot1 == NULL)
		return false;
	if (pRoot2->m_nValue != pRoot1->m_nValue) 
		return false;

	return DoesTree1HaveTree2(pRoot1->m_pLeft, pRoot2->m_pLeft) && DoesTree1HaveTree2(pRoot1->m_pRight, pRoot2->m_pRight);

}

int main() {

	BinaryTreeNode* pNodeA1 = CreateBinaryTreeNode(8);
	BinaryTreeNode* pNodeA2 = CreateBinaryTreeNode(8);
	BinaryTreeNode* pNodeA3 = CreateBinaryTreeNode(7);
	BinaryTreeNode* pNodeA4 = CreateBinaryTreeNode(9);
	BinaryTreeNode* pNodeA5 = CreateBinaryTreeNode(2);
	BinaryTreeNode* pNodeA6 = CreateBinaryTreeNode(4);
	BinaryTreeNode* pNodeA7 = CreateBinaryTreeNode(7);


	ConnectTreeNodes(pNodeA1, pNodeA2, pNodeA3);
	ConnectTreeNodes(pNodeA2, pNodeA4, pNodeA5);
	ConnectTreeNodes(pNodeA5, pNodeA6, pNodeA7);

	BinaryTreeNode* pNodeB1 = CreateBinaryTreeNode(8);
	BinaryTreeNode* pNodeB2 = CreateBinaryTreeNode(9);
	BinaryTreeNode* pNodeB3 = CreateBinaryTreeNode(2);

	ConnectTreeNodes(pNodeB1, pNodeB2, pNodeB3);


	printf("%d\n",HasSubtreeCore(pNodeA1, pNodeB1));
	
	return 0;
}
