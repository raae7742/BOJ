#include <iostream>
#define INDEX 5

using namespace std;

void init() {
	cin.tie(0); cout.tie(0);
	ios_base::sync_with_stdio(false);
}

int vcolor[INDEX];
int m = 3;
int n = 4;
int w[INDEX][INDEX] = {
	{ 0, 0, 0, 0, 0 },
	{ 0, 0, 1, 1, 1 },
	{ 0, 1, 0, 1, 0 },
	{ 0, 1, 1, 0, 1 },
	{ 0, 1, 0, 1, 0 }
};

bool promising(int i) {
	for (int j = 1; j < i; j++) {
		if (w[i][j] && vcolor[i] == vcolor[j])
			return false;
	}

	return true;
}

void m_coloring(int i) {
	if (promising(i)) {
		if (i == n) {
			for (int j = 1; j <= 4; j++) {
				cout << vcolor[j] << " ";
			}
			cout << "\n";
		}
		else {
			for (int j = 1; j <= m; j++) {
				vcolor[i + 1] = j;
				m_coloring(i + 1);
			}
		}
	}
}

int main() {
    init();

	m_coloring(0);
}
