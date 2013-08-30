struct BinaryTreeNode {
	int m_nValue;
	BinaryTreeNode* m_pLeft;
	BinaryTreeNode* m_pRight;
};


BinaryTreeNode* CreateBinaryTreeNode(int value);

void ConnectTreeNodes(BinaryTreeNode* pParent, BinaryTreeNode* pLeft, BinaryTreeNode* pRight);

void PrintTreeNode(BinaryTreeNode* pNode);

void PrintTree(BinaryTreeNode* pNode);

void DestroyTree(BinaryTreeNode* pRoot);
