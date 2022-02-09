#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int N;
bool isPrime(int n);
bool isPalindrome(int n);

void init() {
	cin.tie(0); cout.tie(0);
	ios_base::sync_with_stdio(false);
}

int main() {
	init();
	cin >> N;

	for (int i = N; i <= 2000000; i++) {
		if (isPrime(i) && isPalindrome(i)) {
			cout << i;
			return 0;
		}
	}
	return 0;
}

bool isPrime(int n) {
	if (n < 2) return false;
	for (int i = 2; i * i <= n; i++) {
		if (n % i == 0) return false;
	}
	return true;
}

bool isPalindrome(int n) {
	string s = to_string(n);
	reverse(s.begin(), s.end());
	if (n == atoi(s.c_str())) return true;
	else return false;
}