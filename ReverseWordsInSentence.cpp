#include <stdio.h>
#include <string>
#include "utils/StringUtils.h"

char* ReverseSentence(char* pData) {
	if(pData == NULL)
		return NULL;
	
	char* pBegin = pData;
	char* pEnd = pData;

	while(*pEnd != '\0')
		pEnd++;
	pEnd--;

	Reverse(pBegin, pEnd);

	pBegin = pEnd = pData;

	while(*pBegin != '\0') {
		if(*pBegin == ' ') {
			pBegin++;
			pEnd++;
		} else if (*pEnd == ' ' || *pEnd == '\0') {
			Reverse(pBegin, --pEnd);
			pBegin = ++pEnd;
		} else 
			pEnd++;
	}

	return pData;
}

int main() {
	
	char input[] = "I am a student.";
	ReverseSentence(input);

	printf("%s\n", input);
	return 0;
}
