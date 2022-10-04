#include <iostream>

#define MAX 1000001
#define ll long long
using namespace std;

long long n;

void init() {
    cin.tie(0); cout.tie(0);
    ios_base::sync_with_stdio(false);
}

ll gcd(ll a, ll b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

int main() {
    init();

    cin >> n;

    for (long long i = 0; i < n; i++) {
        ll a, b;
        cin >> a >> b;

        cout << (a * b / gcd(a, b)) << '\n';
    }
}
