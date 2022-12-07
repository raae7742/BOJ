#include <iostream>
#define INDEX 6

using namespace std;

void init() {
	cin.tie(0); cout.tie(0);
	ios_base::sync_with_stdio(false);
}

int n = 5;
int vindex[INDEX];
int w[INDEX][INDEX] = {
	{ 0, 0, 0, 0, 0, 0 },
	{ 0, 0, 1, 0, 0, 1 },
	{ 0, 1, 0, 1, 1, 1 },
	{ 0, 0, 1, 0, 1, 0 },
	{ 0, 0, 1, 1, 0, 0 },
	{ 0, 1, 1, 0, 0, 0 },
};

bool promising(int i) {
	if (i == n - 1 && !w[vindex[n - 1]][vindex[0]])
		return false;
	if (i > 0 && !w[vindex[i-1]][vindex[i]]) 
		return false;

	for (int j = 1; j < i; j++) {
		if (vindex[i] == vindex[j]) return false;
	}

	return true;
}

void hamiltonian(int i) {
	if (promising(i)) {
		if (i == n-1) {
			for (int j = 0; j <= 4; j++) {
				cout << vindex[j] << " ";
			}
			cout << "\n";
		}
		else {
			for (int j = 2; j <= n; j++) {
				vindex[i + 1] = j;
				hamiltonian(i + 1);
			}

		}
	}
}

int main() {
    init();

	vindex[0] = 1;
	hamiltonian(0);
}
