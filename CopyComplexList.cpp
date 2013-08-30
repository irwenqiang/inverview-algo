#include <stdio.h>
#include "ComplexList.h"

void CloneNodes(ComplexListNode* pHead);
void ConnectSiblingNodes(ComplexListNode* pHead);
ComplexListNode* ReconnectNodes(ComplexListNode* pHead);

ComplexListNode* Clone(ComplexListNode* pHead) {
	CloneNodes(pHead);
	ConnectSiblingNodes(pHead);
	return ReconnectNodes(pHead);
}

void CloneNodes(ComplexListNode* pHead) {

	ComplexListNode* pNode = pHead;

	while(pNode != NULL) {
		ComplexListNode* pCloned = new ComplexListNode();
		pCloned->m_nValue = pNode->m_nValue;
		pCloned->m_pNext = pNode->m_pNext;
		pCloned->m_pSibling = NULL;

		pNode->m_pNext = pCloned;

		pNode = pCloned->m_pNext;
	}
}


void ConnectSiblingNodes(ComplexListNode* pHead) {

	ComplexListNode* pNode = pHead;

	while(pNode != NULL) {
		ComplexListNode* pClonedNode = pNode->m_pNext;

		if (pNode->m_pSibling != NULL)
			pClonedNode->m_pSibling = pNode->m_pSibling->m_pNext;
		pNode = pClonedNode->m_pNext;
	}
}

ComplexListNode* ReconnectNodes(ComplexListNode* pHead) {

	ComplexListNode* pClonedHead = NULL;
	ComplexListNode* pNode = pHead;
	ComplexListNode* pClonedNode = NULL;

	if (pNode != NULL) {
		pClonedHead = pClonedNode = pHead->m_pNext;	
		pNode->m_pNext = pClonedNode->m_pNext;	
		pNode = pNode->m_pNext;
	}

	while(pNode != NULL) {
		pClonedNode->m_pNext = pNode->m_pNext;
		pClonedNode = pClonedNode->m_pNext;
		pNode->m_pNext = pClonedNode->m_pNext;

		pNode = pNode->m_pNext;
	}

	return pClonedHead;
}

int main() {
	ComplexListNode* pNode1 = CreateNode(1);
	ComplexListNode* pNode2 = CreateNode(2);
	ComplexListNode* pNode3 = CreateNode(3);
	ComplexListNode* pNode4 = CreateNode(4);
	ComplexListNode* pNode5 = CreateNode(5);

	BuildNodes(pNode1, pNode2, pNode3);
	BuildNodes(pNode2, pNode3, pNode5);
	BuildNodes(pNode3, pNode4, NULL);
	BuildNodes(pNode4, pNode5, pNode2);

	PrintList(pNode1);

	PrintList(Clone(pNode1));
	return 0;

}
