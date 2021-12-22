#include <iostream>
#include <vector>

const int MAX = 100001;
using namespace std;

void init() {
	cin.tie(0); cout.tie(0);
	ios_base::sync_with_stdio(false);
}

int N;
vector<int> adj[MAX];
int root[MAX];
bool visited[MAX];

void dfs(int node) {
	visited[node] = true;

	for (int v : adj[node]) {
		if (!visited[v]) {
			root[v] = node;
			dfs(v);
		}
	}
}

int main() {
	init();
	
	cin >> N;
	for (int i = 0; i < N-1; i++) {
		int node1, node2;

		cin >> node1 >> node2;

		adj[node1].push_back(node2);
		adj[node2].push_back(node1);
	}

	dfs(1);
	
	for (int i = 2; i < N+1; i++)
		cout << root[i] << "\n";

	return 0;
}
