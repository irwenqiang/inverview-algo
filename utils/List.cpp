#include "List.h"
#include <stdio.h>
#include <stdlib.h>

ListNode* CreateListNode(int value) {
	ListNode* node = new ListNode();
	node->m_nValue = value;
	node->m_pNext = NULL;

	return node;
}

void ConnectListNodes(ListNode* pCurrent, ListNode* pNext) {
	pCurrent->m_pNext = pNext;
}

void PrintListNode(ListNode* pNode) {
	printf("%d\n", pNode->m_nValue);
}

void PrintList(ListNode* pHead) {
	ListNode* pNode = pHead;
	while(pNode != NULL) {
		printf("%d\t", pNode->m_nValue);
		pNode = pNode->m_pNext;
	}
	printf("\n");
}

void DestroyList(ListNode* pHead) {
	ListNode* pNode = pHead;
	while(pNode != NULL) {
		pHead = pHead->m_pNext;
		delete pNode;
		pNode = pHead;
	}
}

void AddToTail(ListNode** pHead, int value) {
	ListNode* node = CreateListNode(value);

	if (*pHead == NULL)
		*pHead = node;
	else {
		ListNode *pNode = *pHead;
		while(pNode->m_pNext != NULL) {
			pNode = pNode->m_pNext;
		}

		pNode->m_pNext = node;
	}
}


void RemoveNode(ListNode** pHead, int value) {
	if (*pHead == NULL || pHead == NULL)
		return;
	
	ListNode* pToBeDeleted = *pHead;
	if ((*pHead)->m_nValue == value)
		*pHead = (*pHead)->m_pNext;
	else {
		ListNode* pNode = *pHead;

		while(pNode->m_pNext != NULL && pNode->m_pNext->m_nValue != value) {
			pNode = pNode->m_pNext;
		}

		if (pNode->m_pNext != NULL && pNode->m_pNext->m_nValue == value) {
			pToBeDeleted = pNode->m_pNext;
			pNode->m_pNext = pNode->m_pNext->m_pNext;
		}

	}	

	if(pToBeDeleted != NULL) {
		delete pToBeDeleted;
		pToBeDeleted = NULL;
	}
}
