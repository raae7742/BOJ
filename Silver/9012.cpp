#include <iostream>
#include <stack>

using namespace std;

int T;

void init() {
	cin.tie(0); cout.tie(0);
	ios_base::sync_with_stdio(false);
}

int main() {
	init();

	cin >> T;

	for (int i = 0; i < T; i++) {
		string s;
		bool answer = true;
		stack<char> st;

		cin >> s;
		for (int j = 0; j < s.size(); j++) {
			if (s.at(j) == '(')	st.push(s.at(j));
			if (s.at(j) == ')') {
				if (st.empty()) {
					answer = false;
					break;
				}
				else {
					st.pop();
				}
			}
		}

		if (answer && st.empty()) cout << "YES" << "\n";
		else cout << "NO" << "\n";
	}
}
