#include <iostream>
using namespace std;

int main() {
    long long n, sum, currNum;
    cin >> n;

    sum = n * (n + 1) / 2;
    for (int i = 1; i < n; i++) {
        cin >> currNum;
        sum -= currNum;
    }
    cout << sum << "\n";

    return 0;
}