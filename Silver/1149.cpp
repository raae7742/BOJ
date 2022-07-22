#include <iostream>
#include <algorithm>
#define MAX 1001

using namespace std;

int dp[MAX][3];
int N, sum = 0;

void init() {
	cin.tie(0); cout.tie(0);
	ios_base::sync_with_stdio(false);
}

int main() {
	init();

	cin >> N;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < 3; j++) {
			cin >> dp[i][j];
		}
		
		if (i == 0) continue;
		dp[i][0] = (dp[i - 1][1] < dp[i - 1][2]) ? dp[i][0] + dp[i - 1][1] : dp[i][0] + dp[i - 1][2];
		dp[i][1] = (dp[i - 1][0] < dp[i - 1][2]) ? dp[i][1] + dp[i - 1][0] : dp[i][1] + dp[i - 1][2];
		dp[i][2] = (dp[i - 1][0] < dp[i - 1][1]) ? dp[i][2] + dp[i - 1][0] : dp[i][2] + dp[i - 1][1];
	}

	int sum = (dp[N - 1][0] < dp[N - 1][1]) ? dp[N - 1][0] : dp[N - 1][1];
	sum = (sum < dp[N - 1][2]) ? sum : dp[N - 1][2];
	cout << sum;

}
