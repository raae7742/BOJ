#include <iostream>

using namespace std;

void init() {
	cin.tie(0); cout.tie(0);
	ios_base::sync_with_stdio(0);
}

long long N, A, add, x, y;

long long gcd(long long x, long long y) {
	if (!y) return x;
	return gcd(y, x % y);
}

long long ex_gcd(long long a, long long b, long long& x, long long& y) {
	if (!b) {
		x = 1, y = 0;
		return a;
	}

	long long ret = ex_gcd(b, a % b, x, y);
	long long temp = y;
	y = x - ((a / b) * y);
	x = temp;

	if (x <= 0) {
		x += b;
		y -= a;
	}
	return ret;
}

int main() {
	init();

	cin >> N >> A;

	cout << N - A << " ";

	if (gcd(N, A) != 1) x = -1;		// 서로소가 아닌 경우
	else ex_gcd(A, N, x, y);

	cout << x;

	return 0;
}