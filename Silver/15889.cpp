#include <iostream>
#define MAX 30000

using namespace std;

void init() {
	cin.tie(0); cout.tie(0);
	ios_base::sync_with_stdio(0);
}

int N;
int arr[MAX];
int result = 1;

int main() {
	int length;
	int max_length = 0;
	cin >> N;

	for (int i = 0; i < N; i++) cin >> arr[i];
	for (int i = 0; i < N - 1; i++) {
		cin >> length;
		if (arr[i] + length > max_length) max_length = arr[i] + length;
		if (max_length < arr[i+1]) result = 0;
	}

	if (result || N == 1) cout << "�Ǻ����, �ߴ������ ã���ʴϴ�";
	else cout << "���� �� ���� �ʾ��� �� ����";

	return 0;
}