#include <stdio.h>

void ReorderOddEven(int *pData, unsigned int length) {
	int *begin = pData;
	int *end = pData + length - 1;

	while(begin < end) {
		while(begin < end && (*begin & 1) != 0)
			begin++;
		while(begin < end && (*end & 1) == 0)
			end--;

		if (begin < end) {
			int tmp = *begin;
			*begin = *end;
			*end = tmp;
		}
	}
}
int main() {
	int numbers[] = {2, 4, 6, 1, 3, 5, 7};
	ReorderOddEven(numbers, 7);
	for (int i = 0; i < 7; i++)
		printf("%d\t", numbers[i]);

	printf("\n");
	return 0;
}
