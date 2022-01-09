#include <iostream>
#define MAX 1000

using namespace std;

int C, N;
int arr[MAX];

int main() {
	cin >> C;
	while (C--) {
		cin >> N;

		int sum = 0, cnt = 0, average;
		for (int i = 0; i < N; i++) {
			cin >> arr[i];
			sum += arr[i];
		}

		average = sum / N;
		
		for (int i = 0; i < N; i++) {
			if (arr[i] > average) cnt++;
		}

		double result = cnt * 100 / (double) N;
		cout << fixed;
		cout.precision(3);
		cout << result << "%\n";
	}
}