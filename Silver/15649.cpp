#include <iostream>
#include <vector>
#include <algorithm>
#define long long ll

using namespace std;

int n, m;

void init() {
    cin.tie(0); cout.tie(0);
    ios_base::sync_with_stdio(false);
}

void printNum(vector<int> v, int cnt) {
    if (cnt == m) {
        for (int i = 0; i < v.size(); i++) {
            cout << v[i] << " ";
        }
        cout << "\n";
        return;
    }

    for (int i = 1; i <= n; i++) {
        if (find(v.begin(), v.end(), i) == v.end()) {
            vector<int> temp = v;
            temp.push_back(i);
            printNum(temp, cnt + 1);
        }
    }

}

int main() {
    init();

    cin >> n >> m;

    for (int i = 1; i <= n; i++) {
        vector<int> temp;
        temp.push_back(i);
        printNum(temp, 1);
    }
}
