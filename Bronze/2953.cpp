#include <iostream>

using namespace std;

int score[5][4];

int main() {
    int max = 0;
    int index = -1;

    for (int i = 0; i < 5; i++) {
        int sum = 0;

        for (int j = 0; j < 4; j++) {
            cin >> score[i][j];
            sum += score[i][j];
        }

        if (sum > max) {
            max = sum;
            index = i+1;
        }
    }

    cout << index << " " << max;
}
