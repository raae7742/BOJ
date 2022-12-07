#include <iostream>
#define W 13
#define INDEX 5

using namespace std;

void init() {
	cin.tie(0); cout.tie(0);
	ios_base::sync_with_stdio(false);
}

bool include[INDEX];
int w[] = { 0, 3, 4, 5, 6, 0, 0 };

void sumOfSubset(int i, int weight, int total) {
	if ((weight + total >= W) && (weight == W || (weight + w[i+1] <= W))) {
		if (weight == W) {
			for (int j = 1; j <= 4; j++)
				cout << include[j] << " ";
			cout << "\n";
		}
		else {
			include[i + 1] = true;
			sumOfSubset(i + 1, weight + w[i + 1], total - w[i + 1]);

			include[i + 1] = false;
			sumOfSubset(i + 1, weight, total - w[i + 1]);
		}
			
	}
}

int main() {
    	init();

	sumOfSubset(0, 0, 18);
}
