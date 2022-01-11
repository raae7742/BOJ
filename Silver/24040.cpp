#include <iostream>

using namespace std;

void init() {
	cin.tie(0); cout.tie(0);
	ios_base::sync_with_stdio(0);
}

int T;

int main() {
	cin >> T;

	while (T--) {
		int N;

		cin >> N;

		if ((N % 9) == 0 || (N % 3) == 2) cout << "TAK" << "\n";
		else cout << "NIE" << "\n";
	}
}
