#include <iostream>

using namespace std;

int N, cnt = 0;

void f(int cnt) {
	for (int i = 0; i < cnt; i++) cout << "____";
	cout << "\"����Լ��� ������?\"\n";

	if (cnt == N) {
		for (int i = 0; i < cnt; i++) cout << "____";
		cout << "\"����Լ��� �ڱ� �ڽ��� ȣ���ϴ� �Լ����\"\n";
		return;
	}
	else {
		for (int i = 0; i < cnt; i++) cout << "____";
		cout << "\"�� ����. �������� �� �� ����⿡ �̼��� ��� ������ ����� ������ �־���.\n";
		for (int i = 0; i < cnt; i++) cout << "____";
		cout << "���� ������� ��� �� ���ο��� ������ ������ �߰�, ��� �����Ӱ� ����� �־���.\n";
		for (int i = 0; i < cnt; i++) cout << "____";
		cout << "���� ���� ��κ� �ǾҴٰ� �ϳ�. �׷��� ��� ��, �� ���ο��� �� ���� ã�ƿͼ� ������.\"\n";
		f(++cnt);
	}

	for (int i = 0; i < cnt; i++) cout << "____";
	cout << "��� �亯�Ͽ���.\n";
	return;
}

void init() {
	cin.tie(0); cout.tie(0);
	ios_base::sync_with_stdio(false);
}

int main() {
	init();
	cin >> N;

	cout << "��� �� ��ǻ�Ͱ��а� �л��� ������ �������� ã�ư� ������.\n";
	f(cnt);
	cout << "��� �亯�Ͽ���.\n";
}