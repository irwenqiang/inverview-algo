#include <stdio.h>
#include "utils/List.h"

ListNode* Merge(ListNode* pHead1, ListNode* pHead2) {
	if (pHead1 == NULL)
		return pHead2;
	if (pHead2 == NULL)
		return pHead1;

	ListNode* pHead = NULL;

	if (pHead1->m_nValue > pHead2->m_nValue) {
		pHead = pHead2;
		pHead->m_pNext = Merge(pHead2->m_pNext, pHead1);
	} else {
		pHead = pHead1;
		pHead->m_pNext = Merge(pHead1->m_pNext, pHead2);
	}

	return pHead;
}
int main() {

	ListNode* pNode1 = CreateListNode(1);
	ListNode* pNode3 = CreateListNode(3);
	ListNode* pNode5 = CreateListNode(5);

	ConnectListNodes(pNode1, pNode3);
	ConnectListNodes(pNode3, pNode5);

	ListNode* pNode2 = CreateListNode(2);
	ListNode* pNode4 = CreateListNode(4);
	ListNode* pNode6 = CreateListNode(6);

	ConnectListNodes(pNode2, pNode4);
	ConnectListNodes(pNode4, pNode6);

	PrintList(pNode1);
	PrintList(pNode2);

	PrintList(Merge(pNode1, pNode2));

	return 0;
}
