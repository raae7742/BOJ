#include <iostream>
#include <algorithm>
#define MAX 1000

using namespace std;

void init() {
	cin.tie(0); cout.tie(0);
	ios_base::sync_with_stdio(0);
}

string S;
string arr[MAX];

int main() {
	cin >> S;

	for (int i = 0; i < S.size(); i++) arr[i] = S.substr(i);

	sort(arr, arr + S.size());

	for (int i = 0; i < S.size(); i++)
		cout << arr[i] << "\n";

	return 0;
}