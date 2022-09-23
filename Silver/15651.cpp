#include <iostream>
#include <vector>
#define long long ll

using namespace std;

int n, m;

void init() {
    cin.tie(0); cout.tie(0);
    ios_base::sync_with_stdio(false);
}

void printNum(vector<int> arr, int cnt) {
    if (cnt == m) {
        for (int i = 0; i < arr.size(); i++) {
            cout << arr[i] << " ";
        }
        cout << "\n";
        return;
    }

    for (int i = 1; i <= n; i++) {
        vector<int> temp = arr;
        temp.push_back(i);
        printNum(temp, cnt + 1);
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
