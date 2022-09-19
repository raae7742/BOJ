#include <iostream>
#include <algorithm>
#include <vector>

#define long long ll

using namespace std;

int n, s;

void init() {
    cin.tie(0); cout.tie(0);
    ios_base::sync_with_stdio(false);
}

int main() {
    init();

    cin >> n;

    vector<int> a(n, 0);
    for (int i = 0; i < n; i++) cin >> a[i];
    cin >> s;

    for (int i = 0; i < n; i++) {
        int max = a[i];
        int idx = i;

        for (int j = i + 1; j < n; j++) {
            if (s - (j - i) >= 0) {
                if (max < a[j]) {
                    max = a[j];
                    idx = j;
                }
            }
        }

        for (int j = idx; j > i; j--) {
            swap(a[j], a[j - 1]);
        }
        s -= (idx - i);

        if (s <= 0) break;
    }

    for (int i = 0; i < a.size(); i++) cout << a[i] << " ";
}
