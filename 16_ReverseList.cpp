#include <stdio.h>
#include "utils/List.h"

ListNode* ReverseList(ListNode* pHead) {
	ListNode *pReversedHead = NULL;
	ListNode *pNode = pHead;
	ListNode *pPre = NULL;

	while(pNode != NULL) {
		ListNode *pNext = pNode->m_pNext;

		if (pNext == NULL)
			pReversedHead = pNode;

		pNode->m_pNext = pPre;
		pPre = pNode;
		pNode = pNext;
	}

	return pReversedHead;
}
int main() {

	ListNode* pNode1 = CreateListNode(1);
	ListNode* pNode2 = CreateListNode(2);
	ListNode* pNode3 = CreateListNode(3);
	ListNode* pNode4 = CreateListNode(4);
	ListNode* pNode5 = CreateListNode(5);

	ConnectListNodes(pNode1, pNode2);
	ConnectListNodes(pNode2, pNode3);
	ConnectListNodes(pNode3, pNode4);
	ConnectListNodes(pNode4, pNode5);


	PrintList(pNode1);

	PrintList(ReverseList(pNode1));

	return 0;
}
