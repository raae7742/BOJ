#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

void init() {
    cin.tie(0); cout.tie(0);
    ios_base::sync_with_stdio(false);
}

int main() {
    init();

    int n, t;

    cin >> t;

    for (int temp = 0; temp < t; temp++) {
        unordered_map<string, int> clothes;

        cin >> n;

        for (int i = 0; i < n; i++) {
            string data, key;
            cin >> data >> key;

            if (clothes.find(key) == clothes.end()) {
                clothes[key] = 1;
            }
            else {
                clothes[key]++;
            }
        }
        
        int count = 1;
        for (auto cloth : clothes) {
            count *= (cloth.second + 1);
        }
        count -= 1;

        cout << count << "\n";
        
    }
}
