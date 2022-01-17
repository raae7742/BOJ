#include <iostream>
#include <vector>
#define MAX 100001

using namespace std;

int N, R, Q;
int dp[MAX];
vector<int> v[MAX];

void init() {
	cin.tie(0); cout.tie(0);
	ios_base::sync_with_stdio(0);
}

void dfs(int x, int par) {
	dp[x] = 1;
	for (auto nxt : v[x]) {
		if (nxt == par) continue;
		dfs(nxt, x);
		dp[x] += dp[nxt];
	}
}

int main() {
	init();
	cin >> N >> R >> Q;

	int U, V;
	for (int i = 0; i < N - 1; i++) {
		cin >> U >> V;
		v[U].push_back(V);
		v[V].push_back(U);
	}

	dfs(R, -1);
	while (Q--) {
		int A;
		cin >> A;
		cout << dp[A] << "\n";
	}

	return 0;
}