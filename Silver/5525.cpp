#include <iostream>

using namespace std;

int N, M, result = 0;
string S;

void init() {
	cin.tie(0); cout.tie(0);
	ios_base::sync_with_stdio(0);
}

int main() {
	init();
	cin >> N >> M;
	cin >> S;

	for (int i = 0; i < M; i++) {
		int cnt = 0;
		if (S[i] == 'I') {
			while (S[i+1] == 'O' && S[i+2] == 'I') {
				cnt++;
				if (cnt == N) {
					result++;
					cnt--;
				}
				i += 2;
			}
		}
	}
	cout << result;

}