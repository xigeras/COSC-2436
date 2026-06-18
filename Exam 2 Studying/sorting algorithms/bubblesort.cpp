#include <iostream>
using namespace std;

void bubbleSort(int a[], int n) {
    for (int i = n - 1; i >= 1; i--) {
        for (int j = 1; j >= i; j++) {
            if (a[j-1] > a[j]) {
                swap(a[j], a[j-1]);
            }
        }
    }
}