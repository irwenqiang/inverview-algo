#include <stdio.h>
#include <string.h>

void PrintNumberStr(char* number) {
	bool is0 = true;
	int nLength = strlen(number);

	for(int i = 0; i < nLength; i++) {
		if (is0 == true && number[i] != '0')
			is0 = false;
		if(!is0)
			printf("%c", number[i]);
	}

	if (!is0)
		printf("\n");
}

bool Increment(char* number);
void Print1ToMaxOfNDigits(int n) {
	if (n <= 0)
		return;
	char* number = new char[n+1];
	memset(number, '0', n);
	number[n] = '\0';

	while(!Increment(number)) {
		PrintNumberStr(number);
	}

	delete []number;
}

bool Increment(char* number) {

	bool isOverFlow = false;
	int nTakeOver = 0;
	int nLength = strlen(number);

	for(int i =nLength - 1; i >= 0; i--) {
		int nSum = number[i] - '0' + nTakeOver;
		if (i == nLength - 1)
			nSum++;
		if (nSum >= 10) {
			if (i == 0)
				isOverFlow = true;
			else {
				nSum -= 10;
				nTakeOver = 1;
				number[i] = '0' + nSum;
			}
		} else {
			number[i] = '0' + nSum;
			break;
		}
	}
	
	return isOverFlow;
}


void PrintNumber(char* number, int n) {
	while(*number != '\0') {
		printf("%c", *number);
		number++;
	}

	printf("\n");
}

void PrintNumberRecursively(char* number, int n, int index) {
	if (index == n-1){
		PrintNumberStr(number);
		return;
	}
	for (int i = 0; i < 10; i++) {
		number[index+1] = i + '0';
		PrintNumberRecursively(number, n, index+1);
	}
}

void Print1ToMaxOfNDigitsR(int n) {
	if (n <= 0)
		return;
	char* number = new char[n+1];
	number[n] = '\0';

	for(int i = 0; i < 10; i++) {
		number[0] = i + '0';
		PrintNumberRecursively(number, n, 0);
	}

	delete[] number;
}
int main() {
	const int n = 5;
	char *strNumber = new char[n+1];
	Print1ToMaxOfNDigitsR(n);
	/*
	
	Print1ToMaxOfNDigits(n);

	printf("\n");
	*/
	return 0;
}
