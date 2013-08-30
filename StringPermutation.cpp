#include <stdio.h>

void Permutation(char* pStr, char* pBegin);

void Permutation(char* pStr) {

	if(pStr == NULL)
		return;

	Permutation(pStr, pStr);
}

void Permutation(char* pStr, char* pBegin) {

	if (*pBegin == '\0')
		printf("%s\n", pStr);	
	else {
		for (char* pCh = pBegin; *pCh != '\0'; pCh++) {
			char tmp = *pCh;
			*pCh = *pBegin;
			*pBegin = tmp;

			Permutation(pStr, pBegin+1);

			tmp = *pCh;
			*pCh = *pBegin;
			*pBegin = tmp;
		}
	}
}

int main() {

	char pStr[] = "abc";

	Permutation(pStr);

	return 0;
}


