#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void init() {
	cin.tie(0); cout.tie(0);
	ios_base::sync_with_stdio(0);
}

int N;
vector<string> v;

bool compare(string a, string b) {
	if (a.size() != b.size()) return a.size() < b.size();
	
	int sum_a = 0, sum_b = 0;

	for (char c : a) if (c >= '0' && c <= '9') sum_a += c - '0';
	for (char c : b) if (c >= '0' && c <= '9') sum_b += c - '0';

	if (sum_a != sum_b) return sum_a < sum_b;
	
	return a < b;
}

int main() {
	cin >> N;

	for (int i = 0; i < N; i++) {
		string input;
		cin >> input;
		v.push_back(input);
	}

	sort(v.begin(), v.end(), compare);

	for (int i = 0; i < N; i++) {
		cout << v.at(i) << "\n";
	}
	return 0;
}