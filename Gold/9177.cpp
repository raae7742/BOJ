#include <iostream>
#define MAX 201

using namespace std;

int N;

void init() {
	cin.tie(0); cout.tie(0);
	ios_base::sync_with_stdio(false);
}

int main() {
	init();
	cin >> N;

	for (int n = 1; n <= N; n++) {
		string s1, s2, s3;

		cin >> s1 >> s2 >> s3;
		int l1 = s1.length(), l2 = s2.length();
		bool arr[MAX][MAX];
		arr[0][0] = true;

		for (int i = 1; i <= l1; i++) {
			arr[i][0] = (s1[i - 1] == s3[i - 1]) ? arr[i - 1][0] : false;
		}
		for (int i = 1; i <= l2; i++) {
			arr[0][i] = (s2[i - 1] == s3[i - 1]) ? arr[0][i - 1] : false;
		}
		for (int i = 1; i <= l1; i++) {
			for (int j = 1; j <= l2; j++) {
				char c1 = s1[i - 1], c2 = s2[j - 1], c3 = s3[i + j - 1];
				if (c1 != c3 && c2 != c3) arr[i][j] = false;
				else if (c1 == c3 && c2 != c3) arr[i][j] = arr[i - 1][j];
				else if (c1 != c3 && c2 == c3) arr[i][j] = arr[i][j - 1];
				else arr[i][j] = arr[i - 1][j] || arr[i][j - 1];
			}
		}

		cout << "Data set " << n << ": ";
		if (arr[l1][l2]) cout << "yes";
		else cout << "no";
		cout << "\n";

	}
}