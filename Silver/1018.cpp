#include <iostream>
#define MAX 52

using namespace std;

int N, M, answer = 10000;
char arr[MAX][MAX];
int error[MAX][MAX] = { 0 };

void init() {
	cin.tie(0); cout.tie(0);
	ios_base::sync_with_stdio(false);
}

int main() {
	init();

	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}

	for (int i = 0; i < N - 7; i++) {
		for (int j = 0; j < M - 7; j++) {
			int cnt_black = 0, cnt_white = 0;

			for (int k = i; k < i + 8; k++) {
				for (int m = j; m < j + 8; m++) {
					if ((k + m) % 2 == 0) {
						if (arr[k][m] == 'B')
							cnt_white++;
						else
							cnt_black++;
					}
					else {
						if (arr[k][m] == 'B')
							cnt_black++;
						else
							cnt_white++;
					}
				}
			}
			answer = (answer < cnt_black) ? answer : cnt_black;
			answer = (answer < cnt_white) ? answer : cnt_white;
		}
	}
	cout << answer;
}
