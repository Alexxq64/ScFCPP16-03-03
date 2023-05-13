
#include <iostream>
#include <deque>
using namespace std;

int arr[] = { 1, 2, 3, 1, 4, 5, 2, 3, 6 };
int arr1[] = { 1, 2, 3, 1, 4, 5, 2, 3, 6, 1, 2, 3, 9, 7, 4, 8, 1, 1, 1, 1 };
int arr2[] = { 9,8,7,6,5,4,3,2,1 };

void printKMax(int arr[], int n, int k)
{
	deque<int> d(k);

	for (int i = 0; i < n; i++) {
		if (d.front() == arr[i - k]) {
		d.pop_front();
		}
		while (!d.empty() && arr[i] > d.back()) {
			d.pop_back();
		}
		d.push_back(arr[i]);
		if (i >= k - 1) {
		//	for (size_t j = 0; j < k; j++) {
		//		cout << arr[i - k + j + 1] << " ";
		//	}
		//	cout << "    Max: " << d.front() << " " << "   Step:   " << i << endl;
		//	for (int e:d)	{
		//		cout << e << " ";
		//	}
		//	cout << endl;
			cout << d.front() << " ";
		}
	}
	cout << endl;

}


void printKMax1(int arr[], int n, int k) {

	deque<int> Qi(k);
	int i;
	for (i = 0; i < k; ++i) {
		while ((!Qi.empty()) && arr[i] >= arr[Qi.back()]) {
			Qi.pop_back();
		}
		Qi.push_back(i);
	}


	for (; i < n; ++i) {
		cout << arr[Qi.front()] << " ";
		while ((!Qi.empty()) && Qi.front() <= i - k) {
			Qi.pop_front();
		}
		while ((!Qi.empty()) && arr[i] >= arr[Qi.back()]) {
			Qi.pop_back();
		}
		Qi.push_back(i);
	}


	cout << arr[Qi.front()] << endl;
}

int main()
{

	int k = 4;

	for (size_t i = 0; i < sizeof(arr) / sizeof(int); i++) {
		cout << arr[i] << " ";
	}
	cout << endl;

	printKMax(arr, sizeof(arr) / sizeof(int), k);
	//	printKMax1(arr, sizeof(arr) / sizeof(int), k);

	for (size_t i = 0; i < sizeof(arr1) / sizeof(int); i++) {
		cout << arr1[i] << " ";
	}
	cout << endl;

	printKMax(arr1, sizeof(arr1) / sizeof(int), k);
	//	printKMax1(arr1, sizeof(arr1) / sizeof(int), k);
	printKMax(arr2, sizeof(arr2) / sizeof(int), k);
	//	printKMax1(arr1, sizeof(arr1) / sizeof(int), k);
}