#include <stdio.h>

int MinInOrder(int* number, int index1, int index2) {
	int result = number[index1];
	for (int i = index1; i <= index2; i++){
		if (number[i] < result)
			result = number[i];
	} 

	return result;
}
int MinNumberInRotatedArray(int* array, int length) {
	int index1 = 0;
	int index2 = length - 1;
	int indexMid = index1;

	while(array[index1] >= array[index2]) {
		if (index2 - index1 == 1){
			indexMid = index2;
			break;
		}

		indexMid = (index1 + index2) / 2;

		if (array[index1] == array[index2] && array[index1] == array[indexMid])
			return MinInOrder(array, index1, index2);

		if (array[indexMid] >= array[index1])
			index1 = indexMid;
		else if(array[indexMid] <= array[index2])
			index2 = indexMid;
	}

	return indexMid;
}
int main() {
	
	int array[] = {3, 4, 5,5, 6, 1, 1, 1, 2,2};
	int min = MinNumberInRotatedArray(array, 10);
	printf("%d\n", min);
}
