#include <iostream>
#include <deque>

using namespace std;

int N;
deque<int> q;

void init() {
	cin.tie(0); cout.tie(0);
	ios_base::sync_with_stdio(false);
}

int main() {
	init();

	cin >> N;
	for (int i = N; i > 0; i--) 
		q.push_back(i);

	while (q.size() != 1) {
		q.pop_back();
		int end = q.back();
		q.push_front(end);
		q.pop_back();
	}

	cout << q.front();
}
