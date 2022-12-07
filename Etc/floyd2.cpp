#include <iostream>
#define MAX 1000
#define INDEX 6

using namespace std;

void init() {
    cin.tie(0); cout.tie(0);
    ios_base::sync_with_stdio(false);
}

void print(int n, int d[INDEX][INDEX]) {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++)
            cout << d[i][j] << " ";
        cout << "\n";
    }
}

void path(int q, int r, int p[INDEX][INDEX]) {
    if (p[q][r] != 0) {
        path(q, p[q][r], p);
        cout << p[q][r] << "\n";
        path(p[q][r], r, p);
    }
}

void floyd2(int n, int w[INDEX][INDEX], int d[INDEX][INDEX], int p[INDEX][INDEX]) {

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            p[i][j] = 0;

    d = w;
    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (d[i][k] + d[k][j] < d[i][j]) {
                    p[i][j] = k;
                    d[i][j] = d[i][k] + d[k][j];
                }
            }
        }
    }

    print(n, d);

    // 3 -> 2로 가는 경유 노드 경로
    path(3, 2, p);
}

int main() {
    init();

    int n = 5;

    int w[INDEX][INDEX] = {
        { 0, 0, 0, 0, 0, 0 },
        { 0, 0, 1, MAX, 1, 5 },
        { 0, 9, 0, 3, 2, MAX },
        { 0, MAX, MAX, 0, 4, MAX },
        { 0, MAX, MAX, 2, 0, 3 },
        { 0, 3, MAX, MAX, MAX, 0 }
    };

    int d[INDEX][INDEX];
    int p[INDEX][INDEX];

    floyd2(n, w, d, p);
}
