#include <iostream>
#include <queue>

#define long long ll

using namespace std;

priority_queue<int, vector<int>, greater<int>> pq;
int n;

void init() {
    cin.tie(0); cout.tie(0);
    ios_base::sync_with_stdio(false);
}

int main() {
    init();

    cin >> n;
    for (int i = 0; i < n; i++) {
        int num;
        cin >> num;
        pq.push(num);
    }

    int answer = 0;
    if (pq.size() == 1) {
        answer = 0;
    }
    else {
        while (pq.size() != 1) {
            int sum = 0;

            int temp1 = pq.top();
            pq.pop();

            int temp2 = pq.top();
            pq.pop();

            sum = temp1 + temp2;
            pq.push(sum);
            answer += sum;
        }
    }

    cout << answer;
}
