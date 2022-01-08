#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

void init() {
	cin.tie(0); cout.tie(0);
	ios_base::sync_with_stdio(0);
}

int N, a, b, c;
vector<int> v;
bool possible = false;

int main() {
	cin >> N;

	for (int i = 0; i < N; i++) {
		int input;
		cin >> input;
		v.push_back(input);
	}

	sort(v.begin(), v.end());

	for (int i = N - 2; i >= 1; i--) {
		a = v.at(i - 1); b = v.at(i); c = v.at(i + 1);
		if (c < a + b) {
			possible = true;
			break;
		}
	}

	if (possible) cout << a + b + c;
	else cout << "-1";

}