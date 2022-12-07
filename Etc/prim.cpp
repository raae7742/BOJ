#include <iostream>
#include <vector>

#define MAX		10000
#define INDEX	6

using namespace std;

struct edge {
	int start;
	int end;
};

void init() {
    cin.tie(0); cout.tie(0);
    ios_base::sync_with_stdio(false);
}

void print(vector<edge> f) {
	for (edge e : f) {
		cout << "(" << e.start << ", " << e.end << ")\n";
	}
}

void prim(int n, int w[INDEX][INDEX], vector<edge> f) {

	int nearest[INDEX];
	int distance[INDEX];

	for (int i = 2; i <= n; i++) {					// V_1부터 시작
		nearest[i] = 1;
		distance[i] = w[1][i];
	}

	int vnear;
	for (int j = 2; j <= n; j++) {
		int min = MAX;
		for (int i = 2; i <= n; i++)
			if (0 <= distance[i] && distance[i] < min) {
				min = distance[i];
				vnear = i;							// Y와 가장 가까운 정점 검색
			}

		edge e = edge();
		e.start = nearest[vnear];
		e.end = vnear;

		f.push_back(e);								// 추가된 정점 포함
		distance[vnear] = -1;

		for (int i = 2; i <= n; i++)
			if (w[i][vnear] < distance[i]) {
				distance[i] = w[i][vnear];			// nearest, distance 갱신
				nearest[i] = vnear;
			}
	}

	print(f);
}

int main() {
    init();

	int n = 5;
	int w[INDEX][INDEX] = { 
		{ 0, 0, 0, 0, 0, 0 },
		{ 0, 0, 1, 3, MAX, MAX },
		{ 0, 1, 0, 3, 6, MAX },
		{ 0, 3, 3, 0, 4, 2 },
		{ 0, MAX, 6, 4, 0, 5 },
		{ 0, MAX, MAX, 2, 5, 0 },
	};
	vector<edge> f;

	prim(n, w, f);
}
