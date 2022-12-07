#include <iostream>
#define MAX 1000

using namespace std;

void init() {
    cin.tie(0); cout.tie(0);
    ios_base::sync_with_stdio(false);
}

void print(int d[5][5]) {
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++)
            cout << d[i][j] << " ";
        cout << "\n";
    }
}

void floyd(int n, int w[5][5], int d[5][5]) {
    d = w;
    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
            }
        }
    }

    print(d);
}

int main() {
    init();

    int n = 5;

    int w[5][5] = {
        { 0, 1, MAX, 1, 5 },
        { 9, 0, 3, 2, MAX },
        { MAX, MAX, 0, 4, MAX },
        { MAX, MAX, 2, 0, 3 },
        { 3, MAX, MAX, MAX, 0 }
    };

    int d[5][5];

    floyd(n, w, d);
}
