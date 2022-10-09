#include <iostream>
#define MAX 10001

using namespace std;

int n, arr[MAX] = { 0 };

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
        arr[num]++;

    }
    
    for (int i = 0; i < MAX; i++) {
        for (int j = 0; j < arr[i]; j++) {
            cout << i << '\n';
        }
    }
}
