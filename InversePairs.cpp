#include <stdio.h>
int InversePairsCore(int* data, int* copy, int start, int end);

int InvertPairs(int* data, int length) {
	if (data == NULL || length < 0)
		return 0;
	
	int* copy = new int[length];

	for (int i = 0; i < length; i++)
		copy[i] = data[i];
	
	int count = InversePairsCore(data, copy, 0, length - 1);

	return count;
}

int InversePairsCore(int* data, int* copy, int start, int end) {

	if(start == end) {
		copy[start] = data[start];
		return 0;
	}

	int length = (end - start) / 2;

	int left = InversePairsCore(data, copy, start, start + length);
	int right = InversePairsCore(data, copy, start + length + 1, end);

	int i = start + length;
	int j = end;
	int indexCopy = end;
	int count = 0;

	while(i >= start && j >= start + length + 1) {
		if(data[i] > data[j]) {
			copy[indexCopy--] = data[i--];
			count += j - start - length;
		} else 
			copy[indexCopy--] = data[j--];
	}

	for (; i >= start; i--)
		copy[indexCopy--] = data[i];
	
	for (; j >= start + length + 1; j--)
		copy[indexCopy--] = data[j];

	
	return left + right + count;
	
}



int main() {
	 int data[] = {1, 2, 3, 4, 7, 6, 5};
	 printf("%d\n", InvertPairs(data, 7));

	 return 0;
}
