#include <iostream>
#define long long ll
#define MAX 501

using namespace std;

int n, m, answer = 0;
int arr[MAX][MAX];
int visited[MAX][MAX] = { 0 };

int dx[] = { -1, 0, 0, 1 };
int dy[] = { 0, -1, 1, 0 };

void init() {
    cin.tie(0); cout.tie(0);
    ios_base::sync_with_stdio(false);
}

void tetromino(int i, int j, int cnt, int score) {
    if (cnt == 4) {
        if (answer < score) {
            answer = score;
        }
        return;
    }

    for (int idx = 0; idx < 4; idx++) {
        int x = i + dx[idx];
        int y = j + dy[idx];

        if (x < 0 || x >= n || y < 0 || y >= m || visited[x][y]) continue;
        visited[x][y] = 1;
        tetromino(x, y, cnt + 1, score + arr[x][y]);
        visited[x][y] = 0;
    }

    if (i > 0 && j > 0 && i < n - 1) {
        answer = max(answer, (arr[i - 1][j] + arr[i][j - 1] + arr[i][j] + arr[i + 1][j]));
    }
    if (i > 0 && j < m - 1 && i < n - 1) {
        answer = max(answer, (arr[i - 1][j] + arr[i][j + 1] + arr[i][j] + arr[i + 1][j]));
    }
    if (j > 0 && j < m - 1 && i < n - 1) {
        answer = max(answer, (arr[i][j] + arr[i + 1][j] + arr[i + 1][j - 1] + arr[i + 1][j + 1]));
    }
    if (j > 0 && j < m - 1 && i < n - 1) {
        answer = max(answer, (arr[i][j - 1] + arr[i][j] + arr[i][j + 1] + arr[i + 1][j]));
    }
}

int main() {
    init();

    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> arr[i][j];
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            visited[i][j] = 1;
            tetromino(i, j, 1, arr[i][j]);
            visited[i][j] = 0;
        }
    }
    
    cout << answer;
}
