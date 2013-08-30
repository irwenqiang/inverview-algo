#include <stdio.h>
#include "utils/List.h"

ListNode* FindKthToTail(ListNode* pListHead, unsigned int k) {
	ListNode* fast = pListHead;
	ListNode* slow = pListHead;

	for (int i = 0; i < k; i++)
		fast = fast->m_pNext;
	while(fast != NULL) {
		fast = fast->m_pNext;
		slow = slow->m_pNext;
	}

	return slow;
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

	PrintListNode(FindKthToTail(pNode1, 5));
	return 0;
}
