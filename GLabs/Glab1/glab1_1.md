#include <iostream>
using namespace std;

void drawRuler (int n) {
    if (n == 0) return;
    drawRuler(n - 1);
    cout << n << " ";
    drawRuler(n - 1);
}

int main() {
    int n;
    cin >> n;

    int totalMarks = 1;
    for (int i = 0; i < n; i++) {
        totalMarks = totalMarks * 2;
    }
    totalMarks = totalMarks - 1;

    cout << totalMarks << "\n";

    drawRuler(n);
    cout << "\n";

    return 0;
}