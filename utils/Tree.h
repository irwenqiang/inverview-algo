#ifndef _TREE_H_
#define _TREE_H_
#include <vector>

struct TreeNode {
	int m_nValue;
	std::vector<TreeNode*> m_vChildren;
};

#endif
