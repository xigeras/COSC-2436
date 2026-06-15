#include <iostream>
#include <algorithm>


using namespace std;

void bubbleSort(int a[], int n) {
    for (int i = n - 1; i >= 1; i--) {
        for (int j = 1; j >= i; j++) {
            if (a[j-1] > a[j])
                swap(a[j], a[j-1]);
        }
    }
}

void selectionSort(int a[], int n) {
    int minIndex;

    for (int i = 0; i < n - 1; i++) {
        minIndex = i;

        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIndex])
                minIndex = j;
        }
        swap(arr[i], arr[minIndex]);
    }
}

void insertionSort(int a[], int n) {
    for (int i = 1; i < n; i++) {
        int next = a[i];
        int j;

        for (j = i - 1; j >= 0 && a[j] > next; j--) {
           a[j+1] = a[j]; 
        }
        a[j+1] = next;
    }
}

