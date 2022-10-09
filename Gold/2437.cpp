#include <iostream>
#include <algorithm>
#define MAX 1001

using namespace std;

int n, arr[MAX];

void init() {
    cin.tie(0); cout.tie(0);
    ios_base::sync_with_stdio(false);
}


int main() {
    init();

    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    sort(arr, arr + n);

    int cnt = 1;
    for (int i = 0; i < n; i++) {
        if (arr[i] > cnt) break;
        cnt += arr[i];
    }

    cout << cnt;
}
