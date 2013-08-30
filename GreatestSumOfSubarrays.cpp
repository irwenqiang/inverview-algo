#include <stdio.h>

int FindGreatestSumOfSubArray(int *data, int length) {
	int curSum = 0;
	int maxSum = -1;

	for (int i = 0; i < length; i++) {
		if (curSum <= 0)
			curSum = data[i];
		else
			curSum += data[i];

		if (curSum > maxSum)
			maxSum = curSum;
	}

	return maxSum;
}

int main() {
	int data[] = {1, -2, 3, 10, -4, 7, 2, -5};
	int nLength = 8;

	int result = FindGreatestSumOfSubArray(data, nLength);

	printf("%d\n", result);

	return 0;
}
