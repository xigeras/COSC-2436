#include <iostream>
using namespace std;


int main() {
    int n;
    cin >> n;

    long long moves = 0;

    for (int i = 0; i < n; i++) {
        long long x;
        cin >> x;

        if (i % 2 == 0) {
            if (x < 1) {
                moves += (1 - x);
            }
        } else {
            if (x > -1) {
                moves += (x - (-1));
            }
        }
    }

    cout << moves << "\n";
    return 0;
}