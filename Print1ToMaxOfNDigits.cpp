#include <stdio.h>

void PrintNumber(char* number, int n) {
	while(*number != '\0') {
		printf("%c", *number);
		number++;
	}

	printf("\n");
}

void PrintNumberRecursively(char* number, int n, int index) {
	if (index == n){
		PrintNumber(number, n);
		return;
	}
	for (int i = 0; i < 10; i++) {
		number[index+1] = i + '0';
		PrintNumberRecursively(number, n, index+1);
	}
}

int main() {
	const int n = 2;
	char *strNumber = new char[n+1];
	PrintNumberRecursively(strNumber, n, 0);
}
