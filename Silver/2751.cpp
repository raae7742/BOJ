#include <iostream>
#include <algorithm>
#define MAX 1000001

using namespace std;

int arr[MAX], n;

void init() {
    cin.tie(0); cout.tie(0);
    ios_base::sync_with_stdio(false);
}


int main() {
    init();
    cin >> n;

    for (int i = 0; i < n; i++)
        cin >> arr[i];

    sort(arr, arr + n);
    for (int i = 0; i < n; i++)
        cout << arr[i] << '\n';
}
