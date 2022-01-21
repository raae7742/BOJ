#include <iostream>
#include <string>

#define MAX_K 101

using namespace std;

int T, k;
string answer;
string words[MAX_K];

void init() {
	cin.tie(0); cout.tie(0);
	ios_base::sync_with_stdio(0);
}

int main() {
	init();
	cin >> T;
	while (T--) {
		bool find = false;
		cin >> k;
		for (int i = 0; i < k; i++) {
			cin >> words[i];
		}
		
		for (int i = 0; i < k; i++) {
			for (int j = 0; j < k; j++) {
				if (i == j) continue;
				bool isPalindrome = true;
				answer = words[i] + words[j];
				int length = answer.length();
				for (int w = 0; w < length / 2; w++){
					if (answer.at(w) != answer.at(length - 1 - w)) {
						isPalindrome = false;
						break;
					}
				}
				if (isPalindrome) {
					find = true;
					break;
				}
			}
			if (find) break;
		}
		if (find) cout << answer << "\n";
		else cout << "0" << "\n";
	}

	return 0;
}