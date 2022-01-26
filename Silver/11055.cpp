#include <iostream>
#define MAX 1001
using namespace std;

int N;
int arr[MAX];

void init() {
	cin.tie(0); cout.tie(0);
	ios_base::sync_with_stdio(false);
}

int main() {
	int dp[MAX] = { 0 };
	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> arr[i];
		dp[i] = arr[i];
		if (i) {
			int max = 0;
			for (int j = 0; j < i; j++)
				if (arr[j] < arr[i])
					if (dp[j] > max) max = dp[j];
			dp[i] += max;
		}
	}
	int answer = 0;
	for (int i = 0; i < N; i++)
		if (dp[i] > answer) answer = dp[i];

	cout << answer;

}