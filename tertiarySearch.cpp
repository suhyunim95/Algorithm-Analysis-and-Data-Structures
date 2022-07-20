#include <iostream>
using namespace std;

int tSearch(int l, int h, int k, int arr[]) {
	if(l <= h) {
		int mid1 = l + (h - l) / 3;
		int mid2 = h - (h - l) / 3;

		if (arr[mid1] == k) {
			return mid1;
		}

		if (arr[mid2] == k) {
			return mid2;
		}

		if (arr[mid1] > k) {
			return tSearch(l, mid1 - 1, k, arr);
		}

		if (arr[mid2] < k) {
			return tSearch(mid2 + 1, h, k, arr);
		}

		else {
			return tSearch(mid1 + 1, mid2 - 1, k, arr);
		}

	}

	else 
		return -1;
}

int main() {
	int l, h, k, whereIsK;
	int arr[] = { 1,2,3,4,5,6,7,8,9 };
	l = 0;
	h = 8;
	
	cout << "Enter the number you want to find" << endl;
	cin >> k;

	whereIsK = tSearch(l, h, k, arr);

	if (whereIsK == -1)
	{
		cout << k << " is not in this array. Try the different number." << endl;
	}

	else
		cout << "The index of " << k << " is: " << whereIsK << endl;

	return 0;
}