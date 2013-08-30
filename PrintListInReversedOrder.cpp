#include <stdio.h>
#include "utils/List.h"
using namespace std;

void PrintListReversingly_Recursively(ListNode* pHead) {	
	if (pHead == NULL)
		return;
	PrintListReversingly_Recursively(pHead->m_pNext);
	printf("%d\t", pHead->m_nValue);
	
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

	PrintListReversingly_Recursively(pNode1);

	printf("\n");

	DestroyList(pNode1);
}
