#include <iostream>
#include <string>

#define long long ll

using namespace std;

string input;
int start_idx = 0, answer = 0, sum = 0;
bool isPlus = true;

void init() {
    cin.tie(0); cout.tie(0);
    ios_base::sync_with_stdio(false);
}

int main() {
    init();
    cin >> input;

    for (int i = 0; i < input.length(); i++) {
        if (input.at(i) == '+') {
            int num = stoi(input.substr(start_idx, i));

            if (isPlus) {
                answer += num;
            }
            else {
                sum += num;
            }
            start_idx = i + 1;
        }
        else if (input.at(i) == '-') {
            int num = stoi(input.substr(start_idx, i));

            if (isPlus) {
                answer += num;
            }
            else {
                sum += num;
                answer -= sum;
                sum = 0;
            }
            isPlus = false;

            start_idx = i + 1;
        }
    }

    int num = stoi(input.substr(start_idx, input.size()));
    if (isPlus) {
        answer += num;
    }
    else {
        sum += num;
    }

    if (!isPlus) answer -= sum;
    cout << answer;
}
