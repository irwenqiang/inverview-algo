#include <stdio.h>
#include "utils/BinaryTree.h"

bool VerifySequenceOfBST(int sequence[], int length) {
	if (sequence == NULL || length <= 0)
		return false;

	int root = sequence[length - 1];

	int i;
	for (i = 0; i < length-1; i++) {
		if (sequence[i] > root)
			break;
	}

	for (int j = i; j < length - 1; j++) {
		if (sequence[j] < root)
			return false;
	}

	bool left = true;

	if (i > 1)
		left = VerifySequenceOfBST(sequence, i);

	bool right = true;
	if (i < length - 1)
		right = VerifySequenceOfBST(sequence,length - 1 - i);


	return left && right;
}

int main() {

	int data[] = {4, 8, 6, 12, 16, 14, 10};
	printf("%d\n",VerifySequenceOfBST(data, 7));

	int data_false[] = {7,4,6,5};
	printf("%d\n", VerifySequenceOfBST(data_false, 4));

	return 0;
}


