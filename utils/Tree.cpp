#include "Tree.h"
#include <stdio.h>

TreeNode* CreateTreeNode(int value) {
	TreeNode* pNode = new TreeNode();
	pNode->m_nValue = value;

	// object can't not be NULL
	//pNode->m_vChildren = NULL;
	return pNode;
}

void ConnectTreeNodes(TreeNode* pParent, TreeNode* pChild) {
	if(pParent == NULL || pChild == NULL)
		return;
	
	pParent->m_vChildren.push_back(pChild);
}

void PrintTreeNode(TreeNode* pNode) {
	if (pNode != NULL) {
		std::vector<TreeNode*>::iterator iter = pNode->m_vChildren.begin();
		while(iter != pNode->m_vChildren.end()) {
			if (*iter != NULL) 
				printf("%d\n", (*iter)->m_nValue);
			iter++;
		}
	}	
}

void PrintTree(TreeNode* pRoot) {
	PrintTreeNode(pRoot);
	if (pRoot != NULL) {
		std::vector<TreeNode*>::iterator iter = pRoot->m_vChildren.begin();
		while(iter < pRoot->m_vChildren.end()) {
			PrintTree((*iter));
			iter++;
		}
	}	
}

void DestroyTree(TreeNode* pRoot) {
	if(pRoot != NULL) {
		std::vector<TreeNode*>::iterator iter = pRoot->m_vChildren.begin();
		while(iter < pRoot->m_vChildren.end()) {
			DestroyTree(*iter);
			iter++;
		}

		delete pRoot;
	}	
}
