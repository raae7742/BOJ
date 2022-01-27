#include <iostream>
#define INF 1000000000
#define MAX 501
using namespace std;

int N;
int input[MAX][2], dp[MAX][MAX];

void init() {
	cin.tie(0); cout.tie(0);
	ios_base::sync_with_stdio(false);
}

int main() {
	cin >> N;

	for (int i = 1; i <= N; i++)
		cin >> input[i][0] >> input[i][1];

	for (int i = 1; i < N; i++) {
		for (int j = 1; i + j <= N; j++) {
			dp[j][i + j] = INF;
			for (int k = j; k <= i + j; k++) {
				dp[j][i + j] = min(dp[j][i + j], dp[j][k] + dp[k + 1][i + j] + input[j][0] * input[k][1] * input[i + j][1]);
			}
		}
	}

	cout << dp[1][N];
}