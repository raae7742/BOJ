#include <iostream>
#define COUNT 4

using namespace std;

void init() {
    cin.tie(0); cout.tie(0);
    ios_base::sync_with_stdio(false);
}

void print(int cc[COUNT]) {
    for (int i = 0; i < COUNT; i++) {
        cout << cc[i] << " ";
    }
}

// Greedy Algorithm
void minChange(int changes[], int amount, int cc[COUNT]) {
    for (int i = 0; i < COUNT; i++)
        cc[i] = 0;

    for (int i = 0; i < COUNT; i++) {
        while (amount >= changes[i]) {
            cc[i]++;
            amount = amount - changes[i];
        }
    }

    print(cc);
}

int main() {
    init();

    int amount;
    int changes[] = { 500, 100, 50, 10 };
    int cc[COUNT];

    cout << "거스름돈 입력: ";
    cin >> amount;

    minChange(changes, amount, cc);
}
