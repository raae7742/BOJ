#include <iostream>
#include <queue>
#include <algorithm>

#define MAX 8

using namespace std;

int n, m, result = 0;
int path[MAX][MAX];
int temp[MAX][MAX];

int dx[] = { 0, 1, 0, -1 };
int dy[] = { 1, 0, -1, 0 };

void init() {
    cin.tie(0); cout.tie(0);
    ios_base::sync_with_stdio(false);
}

void bfs() {
    int spread[MAX][MAX];

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            spread[i][j] = temp[i][j];
        }
    }

    queue<pair<int, int>> q;
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (spread[i][j] == 2) q.push({ i, j });
        }
    }

    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx < 0 || nx >= n) continue;
            if (ny < 0 || ny >= m) continue;

            if (spread[nx][ny] == 0) {
                spread[nx][ny] = 2;
                q.push({ nx, ny });
            }
        }
    }

    int cnt = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (spread[i][j] == 0) cnt++;
        }
    }

    result = max(result, cnt);
}

void makeWall(int cnt) {
    if (cnt >= 3) {
        bfs();
        return;
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (temp[i][j] == 0) {
                temp[i][j] = 1;
                makeWall(cnt + 1);
                temp[i][j] = 0;
            }
        }
    }
}


int main() {
    init();

    int cnt = 0;

    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> path[i][j];
            temp[i][j] = path[i][j];
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (path[i][j] == 0) {
                temp[i][j] = 1;
                makeWall(1);
                temp[i][j] = 0;
            }
        }
    }

    cout << result;
}
