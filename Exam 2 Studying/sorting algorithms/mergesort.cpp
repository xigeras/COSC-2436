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


