#include <iostream>
#define MAX 1000

using namespace std;

int n;
int arr[MAX];
int dp[MAX];

void init() {
    cin.tie(0); cout.tie(0);
    ios_base::sync_with_stdio(false);
}

int main() {
    init();
    
    cin >> n;

    for (int i = 0; i < n; i++)
        cin >> arr[i];

    dp[0] = 1;
    for (int i = 0; i < n; i++) {
        int max = 0;
        for (int j = 0; j < i; j++) {
            if (dp[j] > max && arr[j] < arr[i]) max = dp[j];
        }

        dp[i] = max + 1;
    }

    int max = 0;
    for (int i = 0; i < n; i++) {
        if (dp[i] > max) max = dp[i];
    }

    cout << max;
}
