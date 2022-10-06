#include <iostream>

#define MAX 1000001

using namespace std;

long long k, n, result = 0;
int len[MAX];

void init() {
    cin.tie(0); cout.tie(0);
    ios_base::sync_with_stdio(false);
}


int main() {
    init();

    cin >> k >> n;

    long long low = 1, high = 0, mid;
    for (long long i = 0; i < k; i++) {
        cin >> len[i];
        if (len[i] > high) high = len[i];
    }

    while (low <= high) {
        mid = (low + high) / 2;
        int cnt = 0;
        for (long long i = 0; i < k; i++) {
            cnt += len[i] / mid;
        }

        if (cnt >= n) {
            low = mid + 1;
            if (result < mid) result = mid;
        }
        else {
            high = mid - 1;
        }
    }

    cout << result;
}
