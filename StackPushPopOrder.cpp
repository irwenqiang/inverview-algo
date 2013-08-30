#include <stdio.h>
#include<stack>

bool IsPopOrder(const int* pPush, const int* pPop, int nLength) {
	bool bPossible = false;

	if (pPush != NULL && pPop != NULL && nLength > 0) {
		const int* pNextPush = pPush;
		const int* pNextPop = pPop;

		std::stack<int> stackData;


		while(pNextPop - pPop < nLength) {

			while(stackData.empty() || *pNextPop != stackData.top()) {
				stackData.push(*pNextPush);
				if (pNextPush - pPush == nLength)
					break;
				pNextPush++;
			}

			if (stackData.top() != *pNextPop)
				break;


			stackData.pop();

			pNextPop++;
		}

		if (stackData.empty() && pNextPop - pPop == nLength)
			bPossible = true;
	}


	return bPossible;
}

int main() {
	const int nLength = 5;
	int push[nLength] = {1, 2, 3, 4, 5};
	//int pop[nLength] = {3, 5, 4, 1, 2};
	int pop[nLength] = {4, 5, 3, 2, 1};


	printf("%d\n", IsPopOrder(push, pop, nLength));
	return 0;
}
