#include <iostream>
#include <algorithm>
#include <vector>

#define long long ll

using namespace std;

int n, answer = 0;
vector<int> a, b;

void init() {
    cin.tie(0); cout.tie(0);
    ios_base::sync_with_stdio(false);
}

int main() {
    init();

    cin >> n;

    for (int i = 0; i < n; i++) {
        int a_num;
        cin >> a_num;
        a.push_back(a_num);
    }

    for (int i = 0; i < n; i++) {
        int b_num;
        cin >> b_num;
        b.push_back(b_num);
    }

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    for (int i = 0; i < n; i++) {
        int idx = -1;
        for (int j = 0; j < n; j++) {
            if (b[j] != 0 && b[j] < a[i]) {
                idx = j;
            }

        }
        if (idx != -1) {
            a[i] = 0;
            b[idx] = 0;
            answer += 2;
        }
    }

    for (int i = 0; i < n; i++) {
        if (a[i] == 0) continue;

        for (int j = 0; j < n; j++) {
            if (a[i] == b[j]) {
                b[j] = 0;
                answer++;
                break;
            }
        }
    }

    cout << answer;
}
