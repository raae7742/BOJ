#include <iostream>
#include <queue>
#include <string>
#include <sstream>
#include <vector>
#include <cstring>

#define MAX 101
using namespace std;

int N;
string S, L;
queue<string> q[MAX];
queue<string> words;
bool possible = false;

void init();
queue<string> split(string str, char delimiter);

int main() {
	init();
	cin >> N;
	cin.ignore();

	for (int i = 0; i < N; i++) {
		getline(cin, S);
		q[i] = split(S, ' ');
	}

	getline(cin, L);
	words = split(L, ' ');

	while (!words.empty()) {
		possible = false;
		string word = words.front();
		for (int i = 0; i < N; i++) {
			if (!q[i].empty() && !word.compare(q[i].front())) {
				q[i].pop();
				possible = true;
				break;
			}
		}
		words.pop();

		if (!possible) {
			cout << "Impossible";
			return 0;
		}
	}

	for (int i = 0; i < N; i++) {
		if (!q[i].empty()) possible = false;
	}
	if (possible) cout << "Possible";
	else cout << "Impossible";

	return 0;
}

void init() {
	cin.tie(0); cout.tie(0);
	ios_base::sync_with_stdio(false);
}

queue<string> split(string input, char delimiter) {
	queue<string> answer;
	stringstream ss(input);
	string temp;

	while (getline(ss, temp, delimiter)) {
		answer.push(temp);
	}

	return answer;
}