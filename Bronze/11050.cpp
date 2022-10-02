#include <iostream>

#define MAX 11

using namespace std;

int dp[MAX];

void init() {
    cin.tie(0); cout.tie(0);
    ios_base::sync_with_stdio(false);
}

int factorial(int n) {
    int num = 1;
    for (int i = n; i > 0; i--) {
        num *= i;
    }

    return num;
}

int main() {
    init();

    int n, k;
    cin >> n >> k;

    cout << (factorial(n) / factorial(n - k) / factorial(k));
}
