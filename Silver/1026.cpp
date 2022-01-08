#include <iostream>
#include <algorithm>
#define MAX 50

using namespace std;

void init() {
	cin.tie(0); cout.tie(0);
	ios_base::sync_with_stdio(0);
}

int N;
int A[MAX];
int B[MAX];
int S = 0;

int main() {
	cin >> N;

	for (int i = 0; i < N; i++) cin >> A[i];
	for (int i = 0; i < N; i++) cin >> B[i];

	sort(A, A + N);
	sort(B, B + N);

	for (int i = 0; i < N; i++)
		S += A[i] * B[N - 1 - i];

	cout << S;
	return 0;
}