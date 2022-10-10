#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

int n, m;

void init() {
    cin.tie(0); cout.tie(0);
    ios_base::sync_with_stdio(false);
}

vector<string> split(string input, char delimiter) {
    vector<string> answer;
    stringstream ss(input);
    string temp;

    while (getline(ss, temp, delimiter)) {
        answer.push_back(temp);
    }

    return answer;
}

int gcd(int a, int b) {
    if (a == 0) return b;
    if (b == 0) return a;

    return gcd(b, a % b);
}

int main() {
    init();

    string input;
    cin >> input;
    vector<string> nums = split(input, ':');

    n = stoi(nums[0]);
    m = stoi(nums[1]);

    int div = gcd(n, m);

    cout << n / div << ":" << m / div;

}
