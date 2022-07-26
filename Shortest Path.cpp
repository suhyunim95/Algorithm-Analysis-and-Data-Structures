#include <iostream>
using namespace std;

void floydHeap(int array[], int n, int i) {
	int current = i;
	int lch = 2 * i + 1;
	int rch = 2 * i + 2;

	if (lch < n) {
		if (array[i] > array[lch]) {
			current = lch;
		}
	}

	if (rch < n) {
		if (array[current] > array[rch]) {
			current = rch;
		}
	}

	if (current != i) {
		int temp = array[current];
		array[current] = array[i];
		array[i] = temp;
		floydHeap(array, n, current);
	}
}

void visitElement(int array[], int n) {
	int lastpar = (n / 2) - 1;
	for (int i = lastpar; i >= 0; i--) {
		floydHeap(array, n, i);
	}
}

void printer(int array[], int n) {
	for (int i = 0; i < n; i++) {
		cout << array[i] << " ";
	}
}

void heapsort(int array[], int n) {
	for (int i = n - 1; i >= 0; i--) {
		int temp = array[0];
		array[0] = array[i];
		array[i] = temp;
		floydHeap(array, i, 0);
	}
}

int main() {

	int array[] = { 11, 4, 12, 13, 8, 14, 5, 9, 1, 6, 2, 7, 15, 3, 10 };
	int i;
	int n = sizeof(array) / sizeof(array[0]);
	
	cout << "#1: Original array" << endl;
	printer(array, n);
	cout << endl << endl;

	cout << "#2: New array using Floyd's algorithm" << endl;
	visitElement(array, n);
	printer(array, n);
	cout << endl <<endl;

	cout << "#3: Sort array into descending order" << endl;
	heapsort(array, n);
	printer(array, n);
	cout << endl << endl;

	return 0;
}