#include <iostream>
#include <stdlib.h>
#include <exception>
#include "Array.h"

int RandomInRange(int min, int max) {
	int random = rand() % (max - min + 1) + min;
	return random;
}

void Swap(int &a, int &b) {
	a = a^b;
	b = a^b;
	a = a^b;
}

int Partition(int data[], int length, int start, int end) {
	if (data == NULL || length <= 0 || start < 0 || end >= length)
		return -1;
	
	int index = RandomInRange(start, end);

	Swap(data[index], data[end]);

	int small = start - 1;

	for (index = start; index < end; index++) {
		if (data[index] < data[end]) {
			small++;
			if (small != index)
				Swap(data[index], data[small]);
		}
	}

	small++;
	Swap(data[small], data[end]);

	return small;
}
