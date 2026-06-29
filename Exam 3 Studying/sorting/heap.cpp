void heapify(int* arr, int i, int length) {
    if (i >= length) return;
    int lowest == i;

    int left = i * 2 + 1;
    int right = i * 2 + 2;

    if (left < length && arr[left] < arr[lowest]) lowest = left;
    if (right < length && arr[right] < arr[lowest]) lowest = right;

    if (lowest != i) {
        int temp = arr[i];
        arr[i] = arr[lowest];
        arr[lowest] = temp;
        heapify(arr, lowest, length);
    }
}

void buildHeap(int* arr, int n) {
    int i = floor((n-1)/2);

    while (i >= 0) {
        heapify(arr, n, i);
        i--;
    }
}

void heapSort(int* arr, int n) {
    if (n <= 1) return;

    buildHeap(arr, n);

    int temp = arr[0];
    arr[0] = arr[n - 1];
    arr[n - 1] = temp;

    n--;
    while (n > 1) {
        heapify(arr, n, 0);
        temp = arr[0];
        arr[0] = arr[n - 1];
        arr[n - 1] = temp;
    }
}