#include "StringUtils.h"
#include <stdio.h>

void Reverse(char *pBegin, char *pEnd) {
	if (pBegin == NULL || pEnd == NULL)
		return;
	while(pBegin < pEnd) {
		char tmp = *pBegin;
		*pBegin = *pEnd;
		*pEnd = tmp;
		pBegin++;
		pEnd--;
	}
}
