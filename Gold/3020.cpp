#include <iostream>
#include <algorithm>

#define MAX 200001

using namespace std;

int n, h;
int bottom[MAX];
int top[MAX];
int result = MAX, result_cnt = 0;

void init() {
    cin.tie(0); cout.tie(0);
    ios_base::sync_with_stdio(false);
}


int main() {
    init();

    cin >> n >> h;

    for (int i = 0; i < n/2; i++) {
        cin >> bottom[i] >> top[i];
    }

    sort(bottom, bottom + (n / 2));
    sort(top, top + (n / 2));

    for (int i = 1; i <= h; i++) {
        int cnt = lower_bound(bottom, bottom + (n / 2), i) - bottom;
        cnt += upper_bound(top, top + (n / 2), h - i) - top;
        cnt = n - cnt;

        if (result == cnt) result_cnt++;
        else if (result > cnt) {
            result = cnt;
            result_cnt = 1;
        }
    }

    cout << result << ' ' << result_cnt << '\n';
}
