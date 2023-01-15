#include <iostream>
#define MAX 1001

using namespace std;

int arr[MAX][MAX];
bool visited[MAX][MAX];
int dir[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

void init() {
	cin.tie(0); cout.tie(0);
	ios_base::sync_with_stdio(false);
}

void findArea(int i, int j, int n, int m) {
	visited[i][j] = true;
	
	for (int d = 0; d < 4; d++) {
		int newX = i + dir[d][0];
		int newY = j + dir[d][1];
		
		if (newX < 0) newX = n-1;
		if (newX >= n) newX = 0;
		if (newY < 0) newY = m-1;
		if (newY >= m) newY = 0;
		
		if (arr[newX][newY] == 0 && !visited[newX][newY]) 
			findArea(newX, newY, n, m);
	}
}

int main() {
	init();
	
	int n, m, answer = 0;
	
	cin >> n;
	cin >> m;
	
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++) {
			cin >> arr[i][j];
			visited[i][j] = false;
		}
	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (arr[i][j] == 0 && !visited[i][j]) {
				findArea(i, j, n, m);
				answer++;
			}
		}
	}
	
	cout << answer;
	
	
	return 0;
}
