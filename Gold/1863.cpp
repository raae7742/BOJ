#include <iostream>
#include <stack>

using namespace std;

typedef struct point {
	int x; int y;
};

void init() {
	cin.tie(0); cout.tie(0);
	ios_base::sync_with_stdio(false);
}

int n, x, y, cnt = 0;
point p;
stack<point> s;

void solve(point p) {
	while (!s.empty() && p.y < s.top().y) {
		cnt++;
		s.pop();
	}
	if (!s.empty() && s.top().y == p.y) {}
	else s.push(p);
}

int main() {
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> p.x >> p.y;
		solve(p);
	}

	while (!s.empty()) {
		if (s.top().y > 0) cnt++;
		s.pop();
	}
	cout << cnt;
}