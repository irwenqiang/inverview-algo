#include <stdio.h>
#include <vector>
#include "utils/BinaryTree.h"

void FindPath(BinaryTreeNode* pRoot, int expectedSum, std::vector<int>& path, int &currentSum);

void FindPath(BinaryTreeNode* pRoot, int expectedSum) {
	if (pRoot != NULL) {
		int currentSum = 0;
		std::vector<int> path;

		FindPath(pRoot, expectedSum, path, currentSum);
	}
}

void FindPath(BinaryTreeNode* pRoot, int expectedSum, std::vector<int>& path, int &currentSum) {
	currentSum += pRoot->m_nValue;
	path.push_back(pRoot->m_nValue);

	bool isLeaf = pRoot->m_pLeft == NULL && pRoot->m_pRight == NULL;

	if (isLeaf && currentSum == expectedSum) {
		printf("A path is found: ");
		std::vector<int>::iterator iter = path.begin();

		for(; iter != path.end(); iter++)
			printf("%d ", *iter);
		printf("\n");
	}

	if (pRoot->m_pLeft != NULL)
		FindPath(pRoot->m_pLeft, expectedSum, path, currentSum);
	if (pRoot->m_pRight != NULL)
		FindPath(pRoot->m_pRight, expectedSum, path, currentSum);
	//TODO

	currentSum -= pRoot->m_nValue;
	path.pop_back();
}

int main() {

	BinaryTreeNode* pNode10 = CreateBinaryTreeNode(10);
	BinaryTreeNode* pNode5 = CreateBinaryTreeNode(5);
	BinaryTreeNode* pNode12 = CreateBinaryTreeNode(12);
	BinaryTreeNode* pNode4 = CreateBinaryTreeNode(4);
	BinaryTreeNode* pNode7 = CreateBinaryTreeNode(7);

	ConnectTreeNodes(pNode10, pNode5, pNode12);
	ConnectTreeNodes(pNode5, pNode4, pNode7);
	
	FindPath(pNode10, 22);

	return 0;
}
