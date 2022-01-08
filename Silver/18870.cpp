#include <iostream>
#include <algorithm>
#include <vector>

#define MAX 1000000

using namespace std;

void init() {
	cin.tie(0); cout.tie(0);
	ios_base::sync_with_stdio(0);
}

int N;
vector<int> v_sort;
vector<int> v;

int main() {
	cin >> N;

	for (int i = 0; i < N; i++) {
		int input;
		cin >> input;
		v.push_back(input);
		v_sort.push_back(input);
	}
	
	sort(v_sort.begin(), v_sort.end());
	v_sort.erase(unique(v_sort.begin(), v_sort.end()), v_sort.end());

	for (int i = 0; i < N; i++) {
		cout << lower_bound(v_sort.begin(), v_sort.end(), v[i]) - v_sort.begin() << " ";
	}

}