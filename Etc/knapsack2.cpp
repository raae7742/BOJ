#include <iostream>
#include <queue>

#define W 16

using namespace std;

struct node {
	int level;
	int profit;
	int weight;
	float bound;
};

void init() {
	cin.tie(0); cout.tie(0);
	ios_base::sync_with_stdio(false);
}

int n = 4;

int p[] = { 0, 40, 30, 50, 10 };
int w[] = { 0, 2, 5, 10, 5 };

int maxprofit = 0;

float bound(node u) {
	if (u.weight >= W) return 0;

	int totweight = u.weight;
	int result = u.profit;
	int j = u.level + 1;

	while (j <= n && totweight + w[j] <= W) {
		totweight += w[j];
		result += p[j];
		j++;
	}

	if (j <= n) result += (W - totweight) * p[j] / w[j];
	return result;
}

void knapsack2() {
	queue<node> q;

	node v = node();
	v.level = 0;
	v.profit = 0;
	v.weight = 0;
	maxprofit = 0;
	q.push(v);

	while (!q.empty()) {
		node v = q.front();
		q.pop();

		node u = node();
		
		u.level = v.level + 1;
		u.weight = v.weight + w[u.level];
		u.profit = v.profit + p[u.level];

		if (u.weight <= W && u.profit > maxprofit)
			maxprofit = u.profit;

		if (bound(u) > maxprofit) q.push(u);

		u.weight = v.weight;
		u.profit = v.profit;
		if (bound(u) > maxprofit) q.push(u);
	}
}

int main() {
    init();

	knapsack2();

	cout << maxprofit;
}
