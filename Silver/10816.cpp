#include <iostream>
#include <algorithm>

using namespace std;

int N, M, input;
int arr[500001];
int key[500001];

void init() {
	cin.tie(0); cout.tie(0);
	ios_base::sync_with_stdio(false);
}

int main() {
	init();

	cin >> N;
	for (int i = 0; i < N; i++)
		cin >> arr[i];

	sort(arr, arr + N);

	cin >> M;
	for (int i = 0; i < M; i++) {
		cin >> input;
		key[i] = upper_bound(arr, arr + N, input) - lower_bound(arr, arr + N, input);
	}

	for (int i = 0; i < M; i++) {
		cout << key[i] << " ";
	}
	
}

