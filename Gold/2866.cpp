#include <iostream>
#include <vector>
#include <algorithm>

#define MAX 1001

using namespace std;

int R, C;
string table[MAX];

void init() {
	cin.tie(0); cout.tie(0);
	ios_base::sync_with_stdio(0);
}

void binarySearch() {
	int start = 0, end = R-1;

	while (start<=end) {
		int mid = (start + end) / 2;
		vector<string> v;
		bool check = true;

		for (int i = 0; i < C; i++) {
			string temp = "";
			for (int j = mid; j < R; j++) {
				temp += table[j][i];
			}
			if (find(v.begin(), v.end(), temp) == v.end())
				v.push_back(temp);
			else {
				check = false;
				break;
			}
		}

		if (check) {
			start = mid + 1;
		}
		else {
			end = mid - 1;
		}
	}
	cout << start - 1;
}

int main() {
	init();

	cin >> R >> C;
	for (int i = 0; i < R; i++)
		cin >> table[i];

	binarySearch();
}