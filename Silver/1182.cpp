#include <iostream>

using namespace std;

int N, S, cnt = 0;
int arr[21];

void init() {
	cin.tie(0); cout.tie(0);
	ios_base::sync_with_stdio(false);
}

void solve(int idx, int sum) {
	if (idx >= N) {
		return;
	}

	sum += arr[idx];
	if (sum == S) {
		cnt++;
	}
	solve(idx + 1, sum);
}

int main() {
	init();
	cin >> N >> S;

	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}

	for (int i = 0; i < N; i++) {
		solve(i, 0);
	}

	cout << cnt;
	return 0;
}