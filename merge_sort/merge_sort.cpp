#include <iostream>
using namespace std;

void Merge(int *array, int low, int mid, int high) {
	int m = mid - low + 1;
	int n = high - mid;
	int* a = new int[m];
	int* b = new int[n];
	for (int i = 0; i < m; i++) {
		a[i] = array[low + i];
	}
	for (int i = 0; i < m; i++) {
		b[i] = array[mid + 1 + i];
	}
	int i = 0;int j = 0;int k = 0;
    //the elements in array a and b should be in order
	while (i < m && j < n) {
		if (a[i] < b[j])
			array[low + k] = a[i++];
		else
			array[low + k] = b[j++];
		k++;
	}
	if (i >= m) {
		while (j < n) {
			array[low + k] = b[j++];
			k++;
		}
	} else {
		while (i < m) {
			array[low + k] = a[i++];
			k++;
		}
	}
	delete []a;
	delete []b;
}
//by increasement order,T(n)=O(nlog(n))
void MergeSort(int* array, int low, int high) {
	if (low < high) {
		int mid = (low + high) / 2;
		MergeSort(array, low, mid);
		MergeSort(array, mid + 1, high);
		Merge(array, low, mid, high);
	}

}
void printArray(int* array, int length) {
	for (int i = 0; i < length; i++) {
		cout << array[i] << " ";
	}
}

int main() {
	int a[] = { 1, 7, 2, 3, 4, 5, 7, 8, 9, 10 };
	MergeSort(a, 0, sizeof(a) / sizeof(a[0]) - 1);
	printArray(a, sizeof(a) / sizeof(int));
	return 0;
}
