#include <iostream>
#include <stdio.h>
#include <string>
using namespace std;

char* ReplaceBlank(char str[]) {
	
	if (str == NULL)
		return NULL;
	int cnt = 0;
	int length = 0;
	for (int i =0; ;i++) {
		if (str[i] == '\0')
			break;
		if (str[i] == ' ')
			cnt++;
		length++;
	}
	
	int j = length + cnt * 2;
	
	for (int i = length; i >= 0; i--) {
		if (str[i] == ' '){
			str[j--] = '0';
			str[j--] = '2';
			str[j--] = '%';
		} else 
			str[j--] = str[i];

	}
		
	cout << str << endl;
}
int main() {
	const int length = 100;
	char string[length] = "hello, algorithms .";

	ReplaceBlank(string);
	return 0;
}
