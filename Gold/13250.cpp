#include <iostream>
#include <cstring>

#define MAX 1000000

using namespace std;

int N;
double dp[MAX];

void init() {
	cin.tie(0); cout.tie(0);
	ios_base::sync_with_stdio(0);
}

double f(int x) {
	if (x <= 0) return 0.0;
	double& ret = dp[x];
	if (ret > -0.5) return ret;
	ret = 0.0;
	for (int i = 1; i <= 6; i++) 
		ret += (1 + f(x - i)) / 6.0;
	return ret;
}

int main() {
	init();
	memset(dp, -1, sizeof(dp));
	cin >> N;
	cout << fixed;
	cout.precision(13);
	cout << f(N);
}