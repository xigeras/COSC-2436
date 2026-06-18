#include <iostream>
using namespace std;

void mergeSort(int a[], int lo, int up) {
    int m = (lo + up) / 2;
    if (lo == up) { 
        return;
    } else {
        mergeSort(a, lo, m);
        mergeSort(a, m + 1, up);
        merge(a, lo, m, up);
    }
}