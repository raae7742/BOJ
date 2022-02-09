#include <iostream>
#define MAX 51

using namespace std;

int N;
int arr[MAX][2];
int answer[MAX];

void init() {
	cin.tie(0); cout.tie(0);
	ios_base::sync_with_stdio(false);
}

int main() {
	cin >> N;
	for (int i = 0; i < N; i++)	cin >> arr[i][0] >> arr[i][1];

	for (int i = 0; i < N; i++) {
		int cnt = 1;
		int x = arr[i][0];
		int y = arr[i][1];

		for (int j = 0; j < N; j++) {
			if (i == j) continue;
			if (arr[j][0] > x && arr[j][1] > y) cnt++;
		}

		cout << cnt << " ";
	}
}