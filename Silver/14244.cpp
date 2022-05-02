#include <iostream>

using namespace std;

void init() {
	cin.tie(0); cout.tie(0);
	ios_base::sync_with_stdio(0);
}

int N, M;

int main() {
	init();

	cin >> N >> M;

	for (int i = 0; i < N - M; i++)
		cout << i << ' ' << i + 1 << '\n';

	for (int i = N - M; i < N - 1; i++)
		cout << N - M << ' ' << i + 1 << '\n';
	
}