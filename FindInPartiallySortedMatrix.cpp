#include <iostream>
using namespace std;

bool Find(int matrix[][4], int rows, int columns, int value) {
	bool found = false;

	int i = 0;
	int j = columns - 1;

	while(i < rows && j >= 0) {
		if (matrix[i][j] < value)
			i++;
		else if (matrix[i][j] > value)
			j--;
		else {
			found = true;	
			break;
		}

	}

	return found;
}

bool Find(int* matrix, int rows, int columns, int value) {
	bool found = false;

	int i = 0;
	int j = columns - 1;

	while(i < rows && j >= 0) {
		if (matrix[i*columns + j] < value)
			i++;
		else if (matrix[i*columns + j] > value)
			j--;
		else {
			found = true;	
			break;
		}

	}

	return found;
}
int main() {
	int matrix[][4] = {{1,2,8,9},{2,4,9,12},{4,7,10,13},{6,8,11,15}};
	
	cout << Find(matrix, 4,4,5) << endl;
	cout << Find(matrix, 4,4,1) << endl;
	cout << Find(matrix, 4,4,9) << endl;
	
	cout << Find((int*)matrix, 4,4,9) << endl;

	return 0;
}
