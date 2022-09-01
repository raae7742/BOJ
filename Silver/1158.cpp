#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int N, K;
queue<int> q;
vector<int> answer;

int main() {
    cin >> N >> K;

    for (int i = 0; i < N; i++) {
        q.push(i+1);
    }

    int cnt = 0;
    while(!q.empty()) {
        int num = q.front();
        q.pop();
        cnt++;
        if (cnt == K) {
            answer.push_back(num);
            cnt = 0;
        }
        else {
            q.push(num);
        }
    }

    cout << "<";
    for (int i = 0; i < answer.size(); i++) {
        cout << answer[i];

        if (i != answer.size() - 1) {
            cout << ", ";
        }
    }
    cout << ">";
}
