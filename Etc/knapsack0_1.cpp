#include <iostream>
#define INDEX 5
#define W 16

using namespace std;

void init() {
	cin.tie(0); cout.tie(0);
	ios_base::sync_with_stdio(false);
}

int n = 4;

int p[] = { 0, 40, 30, 50, 10 };
int w[] = { 0, 2, 5, 10, 5 };

int include[INDEX];
int bestset[INDEX];
int maxprofit = 0;
int numbest = 0;

bool promising(int i, int profit, int weight) {
	if (weight > W) return false;

	int totweight = weight;
	float bound = profit;
	int j = i + 1;

	while (j <= n && totweight + w[j] <= W) {
		totweight += w[j];
		bound += p[j];
		j++;
	}

	if (j <= n) {
		bound += ((W - totweight) * p[j] / w[j]);
	}

	return bound > maxprofit;
}

void knapsack(int i, int profit, int weight) {
	if (weight <= W && profit > maxprofit) {
		maxprofit = profit;
		numbest = i;

		for (int j = 1; j <= n; j++) {
			bestset[j] = include[j];
		}
	}

	if (promising(i, profit, weight)) {
		include[i + 1] = 1;
		knapsack(i + 1, profit + p[i + 1], weight + w[i + 1]);

		include[i + 1] = 0;
		knapsack(i + 1, profit, weight);
	}
}

int main() {
    init();

	knapsack(0, 0, 0);

	cout << "maxprofit: " << maxprofit << "\n";
	for (int j = 1; j <= n; j++)
		cout << bestset[j] << " ";
}
