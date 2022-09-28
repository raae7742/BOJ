#include <iostream>
#include <queue>

#define long long ll
#define MAX 101

using namespace std;

int n, m;

int path[MAX][MAX];
int visited[MAX][MAX] = { 0 };
int dist[MAX][MAX];

int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};

queue<pair<int, int>> q;

void init() {
    cin.tie(0); cout.tie(0);
    ios_base::sync_with_stdio(false);
}

void bfs(int x, int y) {
    visited[x][y] = 1;
    q.push(make_pair(x, y));
    dist[x][y]++;

    while (!q.empty()) {
        int tx = q.front().first;
        int ty = q.front().second;

        q.pop();
        for (int i = 0; i < 4; i++) {
            int x_new = tx + dx[i];
            int y_new = ty + dy[i];

            if (x_new < 0 || x_new >= n || y_new < 0 || y_new >= m) continue;
            if (visited[x_new][y_new] == 1 || path[x_new][y_new] == 0) continue;

            visited[x_new][y_new] = 1;
            q.push(make_pair(x_new, y_new));
            dist[x_new][y_new] = dist[tx][ty] + 1;
        }
    }
}

int main() {
    init();
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        string input;
        cin >> input;

        for (int j = 0; j < m; j++) {
            path[i][j] = input.at(j) - '0';
        }
    }

    bfs(0, 0);

    cout << dist[n-1][m-1];
}
