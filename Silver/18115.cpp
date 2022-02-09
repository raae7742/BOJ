#include <iostream>
#include <deque>
#define MAX 1000001
using namespace std;

int N;
int A[MAX];
deque<int> d, answer;

void init() {
	cin.tie(0); cout.tie(0);
	ios_base::sync_with_stdio(false);
}

int main() {
	int temp1, temp2;

	init();
	cin >> N;
	for (int i = 0; i < N; i++) {
		d.push_back(i+1);
	}
	for (int i = 0; i < N; i++) cin >> A[i];

	for (int i = N - 1; i >= 0; i--) {
		switch (A[i]) {
		case 1:
			temp1 = d.front();
			d.pop_front();
			answer.push_back(temp1);
			break;
		case 2:
			temp1 = d.front();
			d.pop_front();
			temp2 = answer.back();
			answer.pop_back();
			answer.push_back(temp1);
			answer.push_back(temp2);
			break;
		case 3:
			temp1 = d.front();
			d.pop_front();
			answer.push_front(temp1);
			break;
		}
	}

	while (!answer.empty()) {
		cout << answer.back() << " ";
		answer.pop_back();
	}

	return 0;


}