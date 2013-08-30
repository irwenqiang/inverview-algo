#include <stdio.h>

int GetFirstK(int* data, int length, int k, int start, int end);
int GetLastK(int* data, int length, int k, int start, int end);

int GetNumberOfK(int* data, int length, int k) {
	
	int number = 0;

	if (data != NULL && length > 0) {
		int first = GetFirstK(data, length, k, 0, length - 1);
		int last = GetLastK(data, length, k, 0, length - 1);

		if (first > -1 && last > -1)
			number = last - first + 1;
	}

	return number;
}

int GetFirstK(int* data, int length, int k, int start, int end) {
	
	if (start > end)
		return -1;
	int middle = (end + start) / 2;

	if (k == data[middle]) {
		if ((middle > 0 && data[middle-1] != k) || middle == 0)
			return middle;
		else
			end = middle - 1;
	} else if (k < data[middle])
		return GetFirstK(data, length, k, start, middle - 1);
	else	
		return GetFirstK(data, length, k, middle + 1, end);
}

int GetLastK(int* data, int length, int k, int start, int end) {
	
	if (start > end)
		return -1;
	int middle = (end + start) / 2;
	if (k == data[middle]) {
		if ((middle < length - 1 && data[middle + 1] != k) || middle == length - 1) 
			return middle;
		else
			start = middle + 1;
	} 
	else if (k > data[middle])
		return GetLastK(data, length, k, middle + 1, end);
	else	
		return GetLastK(data, length, k, start, middle - 1);
}

int main() {
	int data[] = {1, 3, 3, 3, 3, 4, 5};
	int number = GetNumberOfK(data, 7, 3);

	printf("%d\n", number);

	return 0;
}
