#include <iostream>

using namespace std;

int N, M;
int arr[9];

void init() {
	cin.tie(0); cout.tie(0);
	ios_base::sync_with_stdio(false);
}

void solve(int cur, int idx) {
	if (idx == M + 1) {
		for (int i = 1; i <= M; i++) {
			cout << arr[i] << " ";
		}
		cout << "\n";
		return;
	}
	if (cur == N + 1) return;
	arr[idx] = cur;
	solve(cur + 1, idx + 1);
	solve(cur + 1, idx);
}

int main() {
	init();

	cin >> N >> M;
	solve(1, 1);
	
}