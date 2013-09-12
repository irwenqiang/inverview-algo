// 参考资料:http://blog.csdn.net/whuslei/article/details/6442755
#include <iostream>
using namespace std;

template <class T>
class Sorter {	
private:
	const static int maxN = 100;
	T aux[maxN];
	T* a;
	int partition(int l, int r);
	void merge(int l, int m, int r);
	void MinHeapFixUp(int i);
	void MinHeapFixDown(int i, int n);
	void exch(T& a, T&b);
public:	
	Sorter(T* _a){
		a = _a;
	}
	void InsertSort(int n);

	void BubbleSort(int n);

	void QuickSort(int l, int r);

	void SelectSort(int n);

	void MergeSort(int l, int r);

	void MakeMinHeap(int n);

	void MinHeapAdd(int n, int x);

	void MinHeapDelete(int n);

	void HeapSort(int n);

	void print(int n);
};

template <class T> int Sorter<T>::partition(int l, int r) {
	int i = l-1;
	int j = r;
	const T v = a[r];

	for (;;) {
		while(a[++i] < v);
		while(v < a[--j]) {
			if (j == l)
				break;
		}

		if (i >= j)
			break;
		exch(a[i], a[j]);
	}

	exch(a[i], a[r]);

	return i;
}

template <class T> void Sorter<T>::merge(int l, int m, int r) {
	int i, j, k;

	for (i = m + 1; i > l; i--) 
		aux[i-1] = a[i-1];

	for (j = m; j < r; j++) 
		aux[r + m - j] = a[j+1];

	for (k = l; k <= r; k++) {
		if (aux[j] < aux[i])
			a[k] = aux[j--];
		else
			a[k] = aux[i++];
	}
}

template <class T> void Sorter<T>::MinHeapFixUp(int i) {
	int j, tmp;

	tmp = a[i];

	j = (i-1)/2;
	while(j >= 0 && i != 0) {
		if( a[j] <= tmp)
			break;

		a[i] = a[j];	

		i = j;
		j = (i - 1)/2;
	}

	a[i] = tmp;
}

template <class T> void Sorter<T>::MinHeapFixDown(int i, int n) {
	int j, tmp;
	tmp = a[i];
	j = 2 * i + 1;

	while( j < n) {
		if (j + 1 < n && a[j+1] < a[j])
			j++;
		if (a[j] > tmp)
			break;
		
		a[i] = a[j];

		i = j;
		j = 2 * i + 1;

	}

	a[i] = tmp;

}
template <class T> inline void Sorter<T>::exch(T& a, T& b) {
	T tmp = a;
	a = b;
	b = tmp;
}

template <class T> void Sorter<T>::InsertSort(int n) {
	for (int i = 1; i < n; i++) {
		int tmp = a[i];
		int j = i - 1;

		while(j >= 0 && tmp < a[j]) {
			a[j+1] = a[j];
			j--;
		}

		a[j+1] = tmp;
	}	
}

template <class T> void Sorter<T>::BubbleSort(int n) {
	
	for (int i = 0; i < n - 1; i++) {
		for (int j = n - 1; j > i; j--) {
			if (a[j] < a[j-1]) {
				exch(a[j], a[j-1]);	
			}
		}

	}
}

template <class T> void Sorter<T>::QuickSort(int l, int r) {
	
	if (r <= l)
		return;
	
	int i = partition(l, r);

	QuickSort(l, i-1);
	QuickSort(i+1, r);

}

template <class T> void Sorter<T>::SelectSort(int n) {
	
	int k = 0;

	for (int i = 0; i < n - 1; i++) {
		k = i;
		for (int j = i + 1; j < n; j++) {
			if (a[j] < a[k])
				k = j;
		}

		if (k != i) 
			exch(a[i], a[k]);
	}
}

template <class T> void Sorter<T>::MergeSort(int l, int r) {
	int m = (l + r)/2;

	if (r <= l)
		return;
	
	MergeSort(l, m);
	MergeSort(m+1, r);

	merge(l, m, r);
}

template <class T> void Sorter<T>::MinHeapAdd(int n, int x) {
	a[n] = x;
	MinHeapFixUp(n);
}

template <class T> void Sorter<T>::MinHeapDelete(int n) {
	exch(a[0], a[n-1]);
	MinHeapFixDown(0, n - 1);
}

template <class T> void Sorter<T>::MakeMinHeap(int n) {
	for (int i = n / 2 - 1; i >= 0; i--)
		MinHeapFixDown(i, n);
}

template <class T> void Sorter<T>::HeapSort(int n) {
	for (int i = n - 1; i >= 1; i--) {
		exch(a[i], a[0]);
		MinHeapFixDown(0, i);
	}
}

template <class T> void Sorter<T>::print(int n) {
	for (int i = 0; i < n; i++)
		cout << a[i] << "\t";
	cout << endl;
}

int main() {
	
	const int n = 9;
	int a[9] = {4, 8, 3, 4, 5, 6, 11, 9, 1};

	Sorter<int> sorter(a);

	//sorter.InsertSort(n);

	//sorter.BubbleSort(n);

	//sorter.QuickSort(0, 8);
	//sorter.SelectSort(9);

	//sorter.MergeSort(0, 8);

	sorter.MakeMinHeap(n);

	sorter.HeapSort(n);

	sorter.print(n);

	return 0;
}
