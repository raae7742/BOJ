#include <iostream>
#define INDEX 4

using namespace std;

void init() {
	cin.tie(0); cout.tie(0);
	ios_base::sync_with_stdio(false);
}

int col[5];

bool promising(int i) {
	int k = 1;
	bool p = true;

	while (k < i && p) {
		if (col[k] == col[i] || abs(col[i] - col[k]) == i - k) {
			p = false;
			break;
		}
		k++;
	}

	return p;
}

void queens(int i) {
	if (promising(i)) {
		if (i == INDEX) {
			for (int j = 1; j <= INDEX; j++)
				cout << col[j] << " ";
			cout << "\n";
		}
		else
			for (int j = 1; j <= INDEX; j++) {
				col[i + 1] = j;
				queens(i + 1);
			}
	}
}

int main() {
    init();

	queens(0);
}
