#include <iostream>
#include <deque>

using namespace std;

int N, K;
string input;
deque<char> d;

void init() {
	cin.tie(0); cout.tie(0);
	ios_base::sync_with_stdio(false);
}

int main() {
	cin >> N >> K;
	cin >> input;

	for (int i = 0; i < N; i++) {
		while (!d.empty() && K && d.back() < input[i]) {
			d.pop_back();
			K--;
		}
		d.push_back(input[i]);
	}

	for (int i = 0; i < d.size() - K; i++)
		cout << d[i];

	return 0;
}
