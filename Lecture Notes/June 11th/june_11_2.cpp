#include <iostream>

using namespace std;

bool search(int a[], int n, int key) {
    int i = 0;

    while (key != a[i] && i != n-1) {
        i++;
    } 

    if (key == a[i]) {          // if (i==n-1) return false else return true
        return true;
    } else {
        return false;
    }

    if (i == n-1) {
        return false;
    } else {
        return true;
    }
}

bool binarySearch(int a[], int low, int high, int key)  {
    int m = 0;
    
    while (low < high) {
        m = (low + high) / 2;
        if (key == a[m]) {
            return true;
        } 
        else if (key < a[m]) {
            high = m - 1;
        } else {
            low = m + 1;
        }
        return false;
    }
}

int main() {
    int a[100];
    for (int i = 0; i < 100; i++) {
        a[i] = rand()%100;
    }
}