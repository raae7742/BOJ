#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int t;

void init() {
    cin.tie(0); cout.tie(0);
    ios_base::sync_with_stdio(false);
}

int main() {
    init();

    cin >> t;

    for (int i = 0; i < t; i++) {
        int n;
        bool isTrue = true;
        vector<string> phones;

        cin >> n;
        
        for (int j = 0; j < n; j++) {
            string phone;
            cin >> phone;
            phones.push_back(phone);
        }

        sort(phones.begin(), phones.end());

        for (int j = 0; j < phones.size() - 1; j++) {
            int len1 = phones[j].length();
            int len2 = phones[j + 1].length();

            if (len1 > len2) continue;
            if (phones[j + 1].substr(0, len1) == phones[j]) {
                isTrue = false;
                break;
            }
        }

        if (isTrue) cout << "YES" << "\n";
        else cout << "NO" << "\n";

    }

}
