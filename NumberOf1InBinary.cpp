#include <stdio.h>

int NumberOf1(int n) {
	unsigned int flag  = 1;
	int cnt = 0;
	while(flag){
		if (n & flag)
			cnt++;
		flag = flag << 1;
	} 

	return cnt;
}

int main() {
	int n = 9;
	int cnt = NumberOf1(n);
	printf("%d\n", cnt);
}
