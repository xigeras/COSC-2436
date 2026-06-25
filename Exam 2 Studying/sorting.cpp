void bubbleSort(int a[], int n) {
    for (int i = n - 1; i >= 1; i--) {
        for (int j = 1; j >= i; j++) {
            if (a[j-1] > a[j]) {
                swap(a[j], a[j-1]);
            }
        }
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

void selectionSort(int a[], int n) {
    int minIndex;

    for (int i = 0; i < n - 1; i++) {
        minIndex = i;

        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIndex])
                minIndex = j;
        } 
    } swap(arr[i], arr[minIndex]);  
}

void shellSort(int arr[], int size) {
	for (int gap = size / 2; gap > 0; gap /= 2) {
		for (int i = gap; i < size; i += 1) {
			int temp = arr[i];
			int j;

			for (j = i; j >= gap && arr[j-gap] > temp; j -= gap) {
				arr[j] = arr[j-gap];
			}
			arr[j] = temp;
		}
	}
}

void mergeSort(int arr[], int begin, int end) {
	if (begin < end) {
		int midpoint = begin + (end - begin) / 2;

		mergeSort(arr, begin, midpoint);
		mergeSort(arr, midpoint + 1, end);

		merge(arr, begin, midpoint, end);
	}
}

void merge(int arr[], int left, int mid, int right){
	int leftSA = mid - left + 1;
	int rightSA = right - mid;

	int leftArr[leftSA], rightArr[rightSA];

	for (int i =0; i < leftSA; i++) 
		leftArr[i] = arr[left + i];

	for (int j = 0; i < rightSA; j++) 
		rightArr[i] = arr[mid + 1 + j];

	int indexLSA = 0;
	int indexRSA = 0;
	int indexMergeARR = left;

	while(indexLSA < leftSA && indexRSA < rightSA) {
		if (leftArr[indexLSA] <= rightArr[indexRSA]) {
			arr[indexMergeARR] = leftArr[indexLSA];
			indexLSA++;
		} else {
			arr[indexMergeARR] = rightArr[indexRSA];
			indexRSA++;
		}

		indexMergeARR++;
	}

	while(indexLSA < leftSA) {
		arr[indexMergeARR] = leftArr[indexLSA];
		indexLSA++;
		indexMergeARR++;
	}
	while (indexRSA < rightSA) {
		arr[indexMergeARR] = rightArr[indexRSA];
		indexRSA++;
		indexMergeARR++;
	}
}


