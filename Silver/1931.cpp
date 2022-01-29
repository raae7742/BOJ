#include <iostream>
#include <algorithm>

#define MAX 100020

using namespace std;

typedef struct {
	long long start;
	long long end;
} meeting;

bool compare(meeting& a, meeting& b) {
	if (a.end < b.end) {
		return true;
	}
	else if (a.end == b.end) {
		return (a.start < b.start);
	}
	return false;
}

int N, answer = 0;
meeting meetings[MAX];

void init() {
	cin.tie(0); cout.tie(0);
	ios_base::sync_with_stdio(0);
}

int main() {
	init();
	cin >> N;

	for (int i = 0; i < N; i++)
		cin >> meetings[i].start >> meetings[i].end;

	sort(meetings, meetings + N, compare);

	answer++;
	int temp = 0;
	for (int i = 1; i < N; i++) {
		if (meetings[i].start >= meetings[temp].end) {
			answer++;
			temp = i;
		}
	}

	cout << answer;
}