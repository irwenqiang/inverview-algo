#include <stdio.h>
#include "utils/List.h"

void DeleteNode(ListNode** pListHead, ListNode* pToBeDeleted) {
	
	ListNode *pNode = pToBeDeleted;
	if (pToBeDeleted == *pListHead) {
		delete pToBeDeleted;
		pToBeDeleted = NULL;
		*pListHead = NULL;
	}

	if (pToBeDeleted->m_pNext == NULL) {
		ListNode *pNode = *pListHead;
		while(pNode->m_pNext != pToBeDeleted) {
			pNode = pNode->m_pNext;
		}

		delete pToBeDeleted;
		pToBeDeleted = NULL;
		pNode->m_pNext = NULL;
	}

	ListNode *pNext = pToBeDeleted->m_pNext;
	pToBeDeleted->m_nValue = pToBeDeleted->m_pNext->m_nValue;
	pToBeDeleted->m_pNext = pToBeDeleted->m_pNext->m_pNext;

	delete pNext;
	pNext = NULL;
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

	DeleteNode(&pNode1, pNode4);

	PrintList(pNode1);

}
