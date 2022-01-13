#include <iostream>

using namespace std;

void init() {
	cin.tie(0); cout.tie(0);
	ios_base::sync_with_stdio(0);
}

int N, k, cnt = 0;
int arr[1050000];
int sorted[1050000];

void merge(int* arr, int start, int mid, int end) {
	int i = start;
	int j = mid + 1;
	int k = start;

	while (i <= mid && j <= end) {
		if (arr[i] <= arr[j]) {
			sorted[k] = arr[i];
			i++;
		}
		else {
			sorted[k] = arr[j];
			j++;
		}
		k++;
	}

	if (i > mid) {
		for (int t = j; t <= end; t++) {
			sorted[k] = arr[t];
			k++;
		}
	}
	else {
		for (int t = i; t <= mid; t++) {
			sorted[k] = arr[t];
			k++;
		}
	}
	
	for (int t = start; t <= end; t++) {
		arr[t] = sorted[t];
	}
}

void merge_sort(int* arr, int start, int end) {
	if (start < end) {
		int mid = (start + end) / 2;
		merge_sort(arr, start, mid);
		merge_sort(arr, mid + 1, end);
		if ((end - start) > N / k) return;
		merge(arr, start, mid, end);
	}
}

int main() {
	init();

	cin >> N;
	for (int i = 0; i < N; i++)  cin >> arr[i];
	cin >> k;

	merge_sort(arr, 0, N-1);

	for (int i = 0; i < N; i++) {
		cout << arr[i] << " ";
	}
	return 0;
}