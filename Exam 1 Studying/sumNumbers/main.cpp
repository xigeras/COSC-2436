#include <iostream>

using namespace std;


int recursive_sum(int m, int n) {
    if (m == n) {
        return m;
    }
    return m + recursive_sum(m + 1, n); //2 + (3, 4)
}


// sum numbers between n and m
int main() {
    int m = 2, n = 4;

    cout << "Sum = " << recursive_sum(m, n);

    /*
    int sum = 0;
    for (int i = m; i <= n; i++) {
        sum += i;
    }

    cout << "Sum=" << sum;
    */

    return 0;
}