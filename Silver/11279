#include <iostream>
#include <queue>
#include <functional>

using namespace std;

int N;
priority_queue<int> pq;

void init() {
	cin.tie(0); cout.tie(0);
	ios_base::sync_with_stdio(false);
}

int main() {
	init();

	cin >> N;
	for (int i = 0; i < N; i++) {
		int x;
		cin >> x;

		if (x == 0) {
			if (pq.size() > 0) {
				cout << pq.top() << "\n";
				pq.pop();
			}
			else {
				cout << "0" << "\n";
			}
		}
		else if (x > 0) {
			pq.push(x);
		}
	}
}
