#include <iostream>

#define MAX 1001
#define DIV_NUM 10007

using namespace std;

int dp[MAX][MAX] = { 0 };

void init() {
    cin.tie(0); cout.tie(0);
    ios_base::sync_with_stdio(false);
}

int main() {
    init();

    int n, k;
    cin >> n >> k;

    long long sum = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= n; j++) {
            if (i == j || j == 0) {
                dp[i][j] = 1;
                continue;
            }

            dp[i][j] = (dp[i - 1][j] + dp[i - 1][j - 1]) % DIV_NUM;
        }
    }

    cout << dp[n][k];
}
