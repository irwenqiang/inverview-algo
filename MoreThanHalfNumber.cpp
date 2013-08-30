#include <stdio.h>
#include "utils/Array.h"

int MoreThanHalfNum(int* numbers, int length) {
	int middle = length >> 1;
	int start = 0;
	int end = length - 1;
	int index = Partition(numbers, length, start, end);

	while(index != middle) {
		if (index > middle)
			index = Partition(numbers, length, start, index-1);

		if (index < middle)
			index = Partition(numbers, length, index+1, end);
	}

	int result = numbers[middle];

	return result;
}

int main() {

	int numbers[] = {1, 2, 3, 2, 2, 2, 5, 4, 2};
	int r = MoreThanHalfNum(numbers, 9);

	printf("%d\n", r);
	return 0;
}
