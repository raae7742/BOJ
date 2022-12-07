#include <iostream>
#define MAX 100

using namespace std;

int s[MAX];

void init() {
	cin.tie(0); cout.tie(0);
	ios_base::sync_with_stdio(false);
}

void initial() {
	for (int i = 1; i <= 5; i++) {
		s[i] = 6 - i;
	}
}

void print() {
	for (int i = 1; i <= 5; i++) {
		cout << s[i] << " ";
	}
	cout << "\n";
}

void swap(int i, int j) {
	int temp = s[i];
	s[i] = s[j];
	s[j] = temp;
}

void bubbleSort(int n) {
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n - i; j++) {
			if (s[j] > s[j + 1]) {
				swap(j, j+1);
			}
		}
	}
}

void insertionSort(int n) {
	for (int i = 2; i <= n; i++) {
		int x = s[i];
		
		int j;
		for (j = i - 1; (j > 0 && s[j] > x); j--) {
			s[j + 1] = s[j];
		}

		s[j + 1] = x;
	}
}

void selectionSort(int n) {
	for (int i = 1; i <= n - 1; i++) {
		int min = i;
		for (int j = i + 1; j <= n; j++) {
			if (s[j] < s[i]) min = j;
		}
		swap(i, min);
	}
}

int main() {
  init();

  
	initial();

	bubbleSort(5);

	print();


	initial();

	insertionSort(5);

	print();


	initial();

	selectionSort(5);

	print();
}
