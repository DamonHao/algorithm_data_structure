#include <iostream>
using namespace std;
// by increasement order, T(n)=O(n^2)
void insertionSort(int* array, int length) {
	for (int j = 1; j < length; j++) {
		int key = array[j];
		int i = j - 1;
		while (i >= 0 && array[i] > key) {
			array[i + 1] = array[i];
			i--;
		}
		array[i + 1] = key;
	}
}
void printArray(int* array, int length) {
	for (int i = 0; i < length; i++) {
		cout << array[i] << " ";
	}
}

int main() {
	int array[] = { 3, 2, 1, 4, 6, 5 };
	insertionSort(array, sizeof(array) / sizeof(int));
	printArray(array, sizeof(array) / sizeof(int));
	return 0;
}
