#include <iostream>
#include <algorithm>

#define MAX 100020
using namespace std;

typedef struct {
	int a;
	int b;
} menu;

bool compare(menu m1, menu m2) {
	if (m1.a - m1.b > m2.a - m2.b) {
		return true;
	}

	return false;
}

int N, X, cost = 0, sum = 0;
menu menus[MAX];

void init() {
	cin.tie(0); cout.tie(0);
	ios_base::sync_with_stdio(false);
}

int main() {
	cin >> N >> X;
	for (int i = 0; i < N; i++) {
		cin >> menus[i].a >> menus[i].b;
	}

	sort(menus, menus + N, compare);

	cost = 1000 * N;
	for (int i = 0; i < N; i++) {
		if ((X >= cost + 4000) && (menus[i].a > menus[i].b)) {
			cost += 4000;
			sum += menus[i].a;
		}
		else sum += menus[i].b;
	}
	
	cout << sum;

}