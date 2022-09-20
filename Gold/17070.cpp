#include <iostream>
#include <algorithm>
#include <vector>

#define long long ll
#define MAX 17

using namespace std;

int n, answer = 0;
int home[MAX][MAX];

void init() {
    cin.tie(0); cout.tie(0);
    ios_base::sync_with_stdio(false);
}

void movePipe(int r, int c, int degree) {
    if (r > n || c > n || r < 1 || c < 1) {
        return;
    }

    if (home[r][c] == 1) {
        return;
    }

    if (degree == 45 && (home[r - 1][c] == 1 || home[r][c - 1] == 1)) {
        return;
    }
    
    if (r == n && c == n) {
        answer++;
        return;
    }

    if (degree == 0 || degree == 45) {
        movePipe(r, c + 1, 0);
    }

    if (degree == 45 || degree == 90) {
        movePipe(r + 1, c, 90);
    }

    movePipe(r + 1, c + 1, 45);

}

int main() {
    init();
    cin >> n;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> home[i][j];
        }
    }

    movePipe(1, 2, 0);

    cout << answer;
}
