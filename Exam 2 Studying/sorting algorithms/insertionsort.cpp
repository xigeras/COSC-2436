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