#include <iostream>

#define MAX 1000001

using namespace std;

int n, m;
bool arr[MAX] = { 0 };

void init() {
    cin.tie(0); cout.tie(0);
    ios_base::sync_with_stdio(false);
}

int main() {
    init();

    cin >> m >> n;

    for (int i = 2; i * i <= n; i++) {
        if (arr[i] == 1) continue;

        for (int j = i * i; j <= n; j += i) {
            arr[j] = 1;
        }
    }

    for (int i = m; i <= n; i++) {
        if (arr[i] == 0) cout << i << '\n';
    }
}
