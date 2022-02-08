#include <iostream>
#include <stack>
#include <map>

using namespace std;

typedef struct matrix {
	int x;
	int y;
};

void init() {
	cin.tie(0); cout.tie(0);
	ios_base::sync_with_stdio(false);
}

int n;
map<char, matrix> matrixs;
stack<matrix> s;

int main() {
	init();

	cin >> n;
	for (int i = 0; i < n; i++) {
		char name;
		matrix m;
		cin >> name >> m.x >> m.y;
		matrixs[name] = m;
	}

	string input;
	while (cin >> input) {
		matrix m1, m2;
		int sum = 0;


		for (int i = 0; i < input.length(); i++) {
			if (input.length() == 1) break;

			if (input.at(i) == '(') continue;
			else if (input.at(i) == ')') {
				m1 = s.top(); s.pop();
				m2 = s.top(); s.pop();

				if (m1.x != m2.y) {
					sum = -1;
					break;
				}

				matrix m3;
				m3.x = m2.x; m3.y = m1.y;
				sum += (m1.x * m1.y * m2.x);
				s.push(m3);
			}
			else {
				s.push(matrixs[input.at(i)]);
			}
		}

		if (sum == -1) cout << "error\n";
		else cout << sum << "\n";
	}
}