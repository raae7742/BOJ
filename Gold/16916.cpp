#include <iostream>
#include <vector>

using namespace std;

string S, P;

void init() {
	cin.tie(0); cout.tie(0);
	ios_base::sync_with_stdio(0);
}

vector<int> FailFunc(string s) {
	int len = s.length();
	vector<int> failVec(len, 0);
	int j = 0;

	for (int i = 1; i < len; i++) {
		while (j > 0 && s[i] != s[j]) {
			j = failVec[j - 1];
		}
		if (s[i] == s[j]) failVec[i] = ++j;
	}

	return failVec;
}

int KMP(string S, string P) {
	vector<int> failVec = FailFunc(P);
	int j = 0;

	for (int i = 0; i < S.length(); i++) {
		while (j > 0 && S[i] != P[j]) {
			j = failVec[j - 1];
		}
		if (S[i] == P[j]) {
			if (j == P.length() - 1) return 1;
			else j += 1;
		}
	}
	return 0;
}

int main() {
	init();

	cin >> S >> P;
	cout << KMP(S, P);

	return 0;

}