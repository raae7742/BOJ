#include <iostream>
#define MAX 2020202

using namespace std;

void init() {
	cin.tie(0); cout.tie(0);
	ios_base::sync_with_stdio(0);
}

int n, input;
int in[MAX], checked[MAX];

int main() {
	init(); 
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> input;
		in[input]++;
	}

	for (int i = 0; i <= 1; i++) {
		if (!in[i]) {
			cout << i;
			return 0;
		}
	}

	for (int i = 1; i < MAX; i++) {
		if (!in[i]) continue;
		for (int j = 1; j < MAX; j++) {
			if (i * j > MAX) break;
			if (!in[j]) continue;
			checked[i * j] = true;
		}
	}

	for (int i = 2; i < MAX; i++) {
		if (checked[i]) continue;
		cout << i;
		return 0;
	}
}