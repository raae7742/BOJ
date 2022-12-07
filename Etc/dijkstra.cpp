#include <iostream>
#include <vector>
#include <algorithm>

#define MAX		10000
#define INDEX	6

using namespace std;

struct edge {
	int start;
	int end;

	edge(int s, int e) : start(s), end(e) {}
};

void init() {
	cin.tie(0); cout.tie(0);
	ios_base::sync_with_stdio(false);
}

void print(vector<edge> f) {
	for (const edge eg : f) {
		cout << "(" << eg.start << ", " << eg.end << ")\n";
	}
}

void dijkstra(int n, int w[INDEX][INDEX], vector<edge> f) {
	int touch[INDEX];
	int length[INDEX];

	for (int i = 2; i <= n; i++) {
		touch[i] = 1;
		length[i] = w[1][i];
	}

	for (int j = 2; j <= n; j++) {
		int min = MAX, vnear;
		for (int i = 2; i <= n; i++) {
			if (0 <= length[i] && length[i] < min) {
				min = length[i];
				vnear = i;
			}
		}

		edge e = edge(touch[vnear], vnear);
		f.push_back(e);

		for (int i = 2; i <= n; i++) {
			if (w[vnear][i] < length[i]) {
				length[i] = w[vnear][i];
				touch[i] = vnear;
			}
		}

		length[vnear] = -1;
	}

	print(f);
}

int main() {
    init();

	int n = 5;
	int w[INDEX][INDEX] = {
		{ 0, 0, 0, 0, 0, 0 },
		{ 0, 0, 7, 4, 6, 1 },
		{ 0, MAX, 0, MAX, MAX, MAX },
		{ 0, MAX, 2, 0, 5, MAX },
		{ 0, MAX, 3, MAX, 0, MAX },
		{ 0, MAX, MAX, MAX, 1, 0 }
	};
	vector<edge> f;

	dijkstra(n, w, f);
}
