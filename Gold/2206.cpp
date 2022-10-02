#include <iostream>
#include <queue>

#define MAX 1001
#define long long ll

using namespace std;

typedef struct {
    int x;
    int y;
    int wall;
} block;

int n, m;
int path[MAX][MAX];
int visited[MAX][MAX][2];

int dx[] = { 0, 1, 0, -1 };
int dy[] = { 1, 0, -1, 0 };

void init() {
    cin.tie(0); cout.tie(0);
    ios_base::sync_with_stdio(false);
}

int bfs(int start_x, int start_y) {
    queue<block> q;

    visited[start_x][start_y][1] = 1;
    q.push({ start_x, start_y,1 });

    while (!q.empty()) {
        int x = q.front().x;
        int y = q.front().y;
        int wall = q.front().wall;
        q.pop();

        if (x == n-1 && y == m-1) return visited[x][y][wall];

        for (int i = 0; i < 4; i++) {
            int tx = x + dx[i];
            int ty = y + dy[i];

            if (tx < 0 || tx >= n) continue;
            if (ty < 0 || ty >= m) continue;
            if (visited[tx][ty][wall] != 0) continue;
            
            if (path[tx][ty] == 1 && wall == 1) {
                visited[tx][ty][0] = visited[x][y][wall] + 1;
                q.push({tx, ty, 0 });
            }

            if (path[tx][ty] == 0) {
                visited[tx][ty][wall] = visited[x][y][wall] + 1;
                q.push({tx, ty, wall});
            }
        }
    }
    return -1;
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

    cout << bfs(0, 0);
}
