#include <iostream>
#include <vector>
#define MAX  50002
using namespace std;

int dp[MAX][2];
int N;
vector<int> v[MAX];

void init() {
	cin.tie(0); cout.tie(0);
	ios_base::sync_with_stdio(0);
}

void dfs(int x, int par) {
	dp[x][1] = 1;
	for (auto nxt : v[x]) {
		if (nxt == par) continue;
		dfs(nxt, x);
		dp[x][0] += max(dp[nxt][0], dp[nxt][1]);
		dp[x][1] += dp[nxt][0];
	}
}

int main() {
	init();

	cin >> N;
	for (int i = 1; i < N; i++) {
		int C1, C2;
		cin >> C1 >> C2;
		v[C1].push_back(C2);
		v[C2].push_back(C1);
	}

	dfs(1, 0);
	cout << max(dp[1][0], dp[1][1]);


}