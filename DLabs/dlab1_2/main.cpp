#include <iostream>

using namespace std;

int main() {
    int n;
    cout << "What is the size of the array?";
    cin >> n;
    
    long long moves = 0;

    int *arr = new arr[];

    for (int i = 1; i < n; i++) {
        while (arr[i] < arr[i-1]) {
            arr[i] = arr[i] + 1;
            moves++;
        }
    }

    cout << moves << endl;

    return 0;
}


/*
pseudocode

if (n >= x) { 
    n++;
} else {
    return 0;
 }

*/