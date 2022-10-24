#include <iostream>
#define MAX 10000

using namespace std;

int n;
int glasses[MAX];
int drink[MAX];

void init() {
    cin.tie(0); cout.tie(0);
    ios_base::sync_with_stdio(false);
}

int main() {
    init();

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> glasses[i];

        if (i == 0) {
            drink[i] = glasses[i];
            continue;
        }

        if (i == 1) {
            drink[i] = glasses[i] + glasses[i - 1];
            continue;
        }

        int max = drink[i - 1];
        if (i == 2 && max < glasses[i] + glasses[i - 1]) {
            max = glasses[i] + glasses[i - 1];
        }
        else if (max < glasses[i] + glasses[i - 1] + drink[i - 3]) {
            max = glasses[i] + glasses[i - 1] + drink[i - 3];
        }

        if (max < glasses[i] + drink[i - 2]) {
            max = glasses[i] + drink[i - 2];
        }

        drink[i] = max;
    }

    cout << drink[n-1] << '\n';
}
