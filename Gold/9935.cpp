#include <iostream>
#include <string>
#include <stack>

using namespace std;

int n, m;

void init() {
    cin.tie(0); cout.tie(0);
    ios_base::sync_with_stdio(false);
}

int main() {
    init();

    string input, bomb, answer = "";

    cin >> input;
    cin >> bomb;

    for (int i = 0; i < input.length(); i++) {
        answer += input[i];

        if (answer[answer.length() - 1] == bomb[bomb.length() - 1]) {
            int cnt = 1;

            for (int j = bomb.length() - 2; j >= 0; j--) {
                if (answer[answer.length() - 1 - (bomb.length() - 1 - j)] == bomb[j]) {
                    cnt++;
                }
            }

            if (cnt == bomb.length()) {
                for (int j = 0; j < bomb.length(); j++) {
                    answer.pop_back();
                }
            }
        }
    }

    if (answer.empty()) {
        cout << "FRULA" << '\n';
    }
    else {
        cout << answer << '\n';
    }
}
