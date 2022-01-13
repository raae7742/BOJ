#include <iostream>
#include <queue>
#define MAX 10000

using namespace std;

void init() {
	cin.tie(0); cout.tie(0);
	ios_base::sync_with_stdio(0);
}

int N, M, result = 0, sum = 0;
int A[MAX];
queue<int> q;

int main() {
	init();

	cin >> N >> M;
	for (int i = 0; i < N; i++) cin >> A[i];

	for (int i = 0; i < N; i++) {
		sum += A[i];
		q.push(A[i]);

		while (sum > M) {
			sum -= q.front();
			q.pop();
		}

		if (sum == M) {
			while (sum > M) {
				sum -= q.front();
				q.pop();
			}
			result++;
		}
	}

	cout << result;
}