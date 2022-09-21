#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>

#define long long ll

using namespace std;

int n, answer = 0;
vector<pair<int, int>> moving;
stack<int> line[4];


void init() {
    cin.tie(0); cout.tie(0);
    ios_base::sync_with_stdio(false);
}

void hanoi(int num, int start, int end, int bypass) {
    if (num == 1) {
        moving.push_back(make_pair(start, end));
        return;
    }
    hanoi(num - 1, start, bypass, end);
    moving.push_back(make_pair(start, end));
    hanoi(num - 1, bypass, end, start);
}

int main() {
    init();
    cin >> n;

    for (int i = 1; i <= n; i++) {
        line[1].push(i);
    }

    hanoi(n, 1, 3, 2);


    cout << moving.size() << "\n";

    for (int i = 0; i < moving.size(); i++) {
        cout << moving[i].first << " " << moving[i].second << "\n";
    }
}
