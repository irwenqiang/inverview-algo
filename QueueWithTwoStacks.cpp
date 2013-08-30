#include "Queue.h"
#include <stdio.h>
int main() {
	iQueue<char> iqueue;

	iqueue.append('a');
	iqueue.append('b');
	iqueue.append('c');

	printf("%c\n", iqueue.pop());
	printf("%c\n", iqueue.pop());

	iqueue.append('d');
	iqueue.append('e');

	printf("%c\n", iqueue.pop());


}
