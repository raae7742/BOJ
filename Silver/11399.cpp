#include <iostream>
#include <algorithm>
#define MAX 1001

using namespace std;

int N, answer = 0;
int P[MAX];

void init() {
	cin.tie(0); cout.tie(0);
	ios_base::sync_with_stdio(false);
}

int main() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> P[i];
	}

	sort(P, P + N);

	for (int i = 0; i < N; i++) {
		answer += (P[i] * (N - i));
	}

	cout << answer;
}