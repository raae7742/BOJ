#include <iostream>
#include <vector>
#include <algorithm>

#define MAX		10000
#define INDEX	6

using namespace std;

// 분리 집합(Disjoint Set) 자료구조
int parent[MAX];

struct edge {
	int start;
	int end;
	int weight;

	edge(int s, int e, int w) : start(s), end(e), weight(w) {}
};

bool compareTo(edge e1, edge e2) {
	return e1.weight < e2.weight;
}

void init() {
    cin.tie(0); cout.tie(0);
    ios_base::sync_with_stdio(false);
}

void initial(int n) {
	for (int i = 0; i <= n - 1; i++)
		parent[i] = -1;
}

int find(int i) {
	for (; parent[i] >= 0; i = parent[i])
		;
	return i;
}

bool equal(int p, int q) {
	if (p == q) return true;
	else return false;
}

void merge(int p, int q) {
	parent[q] = p;
}

void print(vector<edge> f) {
	for (const edge eg : f) {
		cout << "(" << eg.start << ", " << eg.end << ")\n";
	}
}

void kruskal(int n, vector<edge> e, vector<edge> f) {

	// 가중치에 따라 간선을 오름차순 정렬
	sort(e.begin(), e.end(), compareTo);

	initial(n);

	int idx = 0;
	while (f.size() < n-1) {
		edge eg = e[idx++];
		// p, q에 각 정점의 루트 저장
		int p = find(eg.start);
		int q = find(eg.end);

		if (!equal(p, q)) {
			merge(p, q);
			f.push_back(eg);
		}
		
	}
	print(f);
}

int main() {
    init();

	int n = 5;
	vector <edge> e = {
		edge(1, 2, 1),
		edge(3, 5, 2),
		edge(1, 3, 3),
		edge(2, 3, 3),
		edge(3, 4, 4),
		edge(4, 5, 5),
		edge(2, 4, 6)
	};
	vector<edge> f;

	kruskal(n, e, f);
}
