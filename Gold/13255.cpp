#include <iostream>

using namespace std;

int N, K, A;

void init() {
	cin.tie(0); cout.tie(0);
	ios_base::sync_with_stdio(0);
}

int main() {
	cin >> N >> K;
	double result = N;

	for (int i = 0; i < K; i++) {
		cin >> A;
		double tmp = 0.0;
		tmp += result * (1.0 - (double)A / N);
		tmp += (N - result) * ((double)A / N);
		result = tmp;
	}

	cout << fixed;
	cout.precision(13);
	cout << result;
}