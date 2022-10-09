#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>

#define MAX 100002

using namespace std;

int n;
pair<int, string> members[MAX];

void init() {
    cin.tie(0); cout.tie(0);
    ios_base::sync_with_stdio(false);
}

bool compare(const pair<int, string> a, const pair<int, string> b) {
    return a.first < b.first;
}


int main() {
    int age;
    string name;

    init();

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> age >> name;
        members[i] = { age, name };
    }

    stable_sort(members, members + n, compare);
    

    for (int i = 0; i < n; i++) {
        cout << members[i].first << " " << members[i].second << "\n";
    }
    
}
