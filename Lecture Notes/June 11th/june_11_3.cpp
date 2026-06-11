#include <iostream>

using namespace std;

void bubbleSort(int a[], int n) {
    int h = 0;
    int swap = 0;
    int comp = 0;

    for (int pass = 1; pass < n; pass++) {
        for (int i = 0; i < (n-pass); i++) {
            comp++;

            if (a[i] > a[i+1]) {
                h = a[i];
                a[i] = a[i+1];
                a[i+1] = h;
                swap++;
            }
        }
    }
}

int main() {
    int a1[100]; int a2[10000];
    bubbleSort(a1,100); bubbleSort(a1,100); 
    bubbleSort(a2,10000); bubbleSort(a2,10000);

    return 0;
}