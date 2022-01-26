#include <iostream>
#include <algorithm>

#define MAX 125251
using namespace std;

int N;
int arr[125251];

void init() {
	cin.tie(0); cout.tie(0);
	ios_base::sync_with_stdio(false);
}

int main() {
	cin >> N;
	int cnt = (N * (N + 1)) / 2;
	for (int i = 0; i < cnt; i++) {
		cin >> arr[i];
	}
	
	int column = N, cnt_c = 0;
	while (--cnt) {
		if ((cnt + column + 1) > (N * (N + 1)) / 2) {
			if (++cnt_c == column) {
				cnt_c = 0;
				column--;
			}
			continue;
		}
		arr[cnt] += max(arr[cnt + column], arr[cnt + column + 1]);

		if (++cnt_c == column) {
			cnt_c = 0;
			column--;
		}
	}

	arr[0] += max(arr[1], arr[2]);

	cout << arr[0];

}