#include <stdio.h>
#include <queue>
#include "utils/BinaryTree.h"

void PrintFromTopToBottom(BinaryTreeNode* pRoot) {
	
	if (pRoot != NULL) {	
		std::queue<BinaryTreeNode*> q;
		q.push(pRoot);
		BinaryTreeNode* cur;

		while(!q.empty()) {
			cur = q.front();
			printf("%d\n",cur->m_nValue);
			q.pop();
		
			if (cur->m_pLeft != NULL)
				q.push(cur->m_pLeft);
			if (cur->m_pRight != NULL)
				q.push(cur->m_pRight);
		}

	}
	return;
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

	PrintFromTopToBottom(pNode10);

	return 0;
}

