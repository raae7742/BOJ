#include <iostream>

#define INDEX	4

using namespace std;

void init() {
	cin.tie(0); cout.tie(0);
	ios_base::sync_with_stdio(false);
}

void greedyKnapsack(float m, int n, int p[INDEX], int w[INDEX], float x[INDEX]) {
	
	for (int i = 1; i <= n; i++)
		x[i] = 0.0;

	int i;
	float u = m;
	for (i = 1; i <= n; i++) {
		if (w[i] > u) break;
		x[i] = 1.0;
		u -= w[i];
	}

	if (i <= n)
		x[i] = u / w[i];

	for (int i = 1; i <= n; i++)
		cout << x[i] << "\n";
}

int main() {
    init();

	int m = 30;
	int n = 3;
	int p[] = { 0, 50, 140, 60 };
	int w[] = { 0, 5, 20, 10 };
	float x[INDEX];

	greedyKnapsack(m, n, p, w, x);
}
