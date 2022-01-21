#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <queue>

#define MAX 51

using namespace std;

void init() {
	cin.tie(0); cout.tie(0);
	ios_base::sync_with_stdio(0);
}

int N;
string input;
bool alpha[26];

int main() {
	cin >> N;
	cin.ignore();
	while (N--) {
		queue<char> q;
		memset(alpha, false, 26);
		getline(cin, input);
		for (int i = 0; i < input.length(); i++) {
			char c = input.at(i);
			if (c >= 'a' && c <= 'z') alpha[c - 'a'] = true;
			if (c >= 'A' && c <= 'Z') alpha[c - 'A'] = true;
		}

		for (int i = 0; i < 26; i++) {
			if (!alpha[i]) q.push('a' + i);
		}

		if (!q.size()) cout << "pangram" << "\n";
		else {
			cout << "missing ";
			while (!q.empty()) {
				cout << q.front();
				q.pop();
			}
			cout << "\n";
		}
	}

	return 0;
}