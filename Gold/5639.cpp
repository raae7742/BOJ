#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int nodes[10000];

void init() {
    cin.tie(0); cout.tie(0);
    ios_base::sync_with_stdio(false);
}

void postOrder(int start, int end) {

    if (start >= end) {
        return;
    }

    if (start == end - 1) {
        cout << nodes[start] << "\n";
        return;
    }

    int index = start + 1;

    while (index < end) {
        if (nodes[start] < nodes[index]) {
            break;
        }
        index++;
    }

    postOrder(start + 1, index);
    postOrder(index, end);
    cout << nodes[start] << "\n";
}

int main() {
    init();

    int num;
    int index = 0;
    while (cin >> num) {
        nodes[index] = num;
        index++;
    }

    postOrder(0, index);
}
