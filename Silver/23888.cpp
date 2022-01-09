#include <iostream>

using namespace std;

void init() {
	cin.tie(0); cout.tie(0);
	ios_base::sync_with_stdio(0);
}

int a, d, q;
void print_sum(int l, int r);
void print_gcd(int l, int r);
long long gcd(long long x, long long y);

int main() {
	init();

	cin >> a >> d;
	cin >> q;

	for (int i = 0; i < q; i++) {
		int num, l, r;
		cin >> num >> l >> r;

		switch (num) {
		case 1:
			print_sum(l, r);
			break;
		case 2:
			print_gcd(l, r);
			break;
		}
	}

	return 0;
}

void print_sum(int l, int r) {
	int result = 0;
	for (int i = l; i <= r; i++)
		result += a + (i-1) * d;
	cout << result << "\n";
}

// gcd (a + d, a + 2d, a + 3d) = gcd (a, d)
void print_gcd(int l, int r) {
	if (l == r) cout << a + (r - 1) * d << "\n";
	else cout << gcd(a, d) << "\n";
}

long long gcd(long long x, long long y) {
	if (!y) return x;
	return gcd(y, x % y);
}
