#include <iostream>
#define MAX 1002
using namespace std;

int N;

void init() {
	cin.tie(0); cout.tie(0);
	ios_base::sync_with_stdio(0);
}

int main() {
	init();
	cin >> N;

	int dp[MAX] = { 0 };

	dp[1] = 1;
	dp[2] = 2;
	
	for (int i = 3; i <= N; i++) {
		dp[i] += (dp[i - 1] + dp[i - 2]) % 10007;
	}

	cout << dp[N];
}