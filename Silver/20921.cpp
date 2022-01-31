#include <iostream>
#define MAX 4243
using namespace std;

int N, K;
int u[MAX];

void init() {
	cin.tie(0); cout.tie(0);
	ios_base::sync_with_stdio(false);
}

int main() {
	cin >> N >> K;
	for (int i = 0; i < N; i++) u[i] = i+1;

	int cnt = 0;
	for (int n = 1; n < N; n++) {
		for (int i = N - 1; i > n - 1; i--) {
			if (cnt >= K) break;

			int temp = u[i];
			u[i] = u[i - 1];
			u[i - 1] = temp;
			cnt++;
			for (int i = 0; i < N; i++) cout << u[i] << " ";
			cout << "\n";
		}
		if (cnt >= K) break;
	}

	for (int i = 0; i < N; i++) cout << u[i] << " ";

}