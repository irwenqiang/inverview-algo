#include <stdio.h>


unsigned int FindFirstBitIs1(int num);
bool IsBit1(int num, unsigned int indexBit);

void FindNumsAppearOnce(int data[], int length, int* num1, int* num2) {

	if (data == NULL || length < 2)
		return;
	
	int resultXOR = 0;

	for (int i = 0; i < length; i++)
		resultXOR ^= data[i];
	
	unsigned int indexOf1 = FindFirstBitIs1(resultXOR);

	*num1 = *num2 = 0;

	for (int i = 0; i < length; i++) {
		if (IsBit1(data[i], indexOf1))
			*num1 ^= data[i];
		else
			*num2 ^= data[i];
	}
}


inline unsigned int FindFirstBitIs1(int num) {
	
	int index = 0;

	while(((num & 1) == 0) && (index < 8 * sizeof(int))) {
		num = num >> 1;
		index++;
	}
	return index;
}

inline bool IsBit1(int num, unsigned int indexBit) {
	num = num >> indexBit;
	return (num & 1);
}


int main() {
	int data[] = {2, 4, 3, 6, 3, 2, 5, 5};
	int num1;
	int num2;

	FindNumsAppearOnce(data, sizeof(data)/sizeof(int), &num1, &num2);

	printf("%d\t%d\n", num1, num2);

	return 0;
}
