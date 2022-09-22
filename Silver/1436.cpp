#include <iostream>
#include <string>

#define long long ll

using namespace std;

int n, answer;

void init() {
    cin.tie(0); cout.tie(0);
    ios_base::sync_with_stdio(false);
}

int main() {
    init();

    cin >> n;

    int idx = 0;
    for (int i = 0; i < 66666666; i++) {
        string num = to_string(i);
        int cnt = 0;
        for (int j = 0; j < num.length(); j++) {
            if (num.at(j) == '6') {
                if (++cnt == 3) {
                    break;
                }
            }
            else {
                cnt = 0;
            }
        }

        if (cnt == 3) {
            if (++idx == n) {
                answer = i;
                break;
            }
        }
    }

    cout << answer;
}
