void mergeSort(int arr[], int begin, int end) {
	if (begin < end) {
		int midpoint = begin + (end - begin) / 2;

		mergeSort(arr, begin, midpoint);
		mergeSort(arr, midpoint + 1, end);

		merge(arr, begin, midpoint, end);
	}
}

void merge(int arr[], int left, int mid, int right){
	int leftSubArray = mid - left + 1;
	int rightSubArray = right - mid;

	int leftArray[leftSubArray], rightArray[rightSubArray];

	for (int i =0; i < leftSubArray; i++) 
		leftArray[i] = arr[left + i];

	for (int j = 0; i < rightSubArray, j++) 
		rightArray[i] = arr[mid + 1 + j];

	int indexOfLeftSubArray = 0;
	int indexOfRightSubArray = 0;
	int indexofMergedArray = left;

	while(indexOfLeftSubArray < leftSubArray && indexOfRightSubArray < rightSubArray) {
		if (leftArray[indexofLeftSubArray] <= rightArray[indexOfRightSubArray]) {
			arr[indexOfMergedArray] = leftArray[indexOfLeftSubArray];
			indexOfLeftSubArray++;
		} else {
			arr[indexOfMergedArray] = rightArray[indexOfRightSubArray];
			indexOfRightSubArray++;
		}

		indexOfMergedArray++;
	}

	while(indexOfLeftSubArray < leftSubArray) {
		arr[indexOfMergedArray] = leftArray[indexOfLeftSubArray];
		indexOfLeftSubArray++;
		indexOfMergedArray++;
	}
	while (indexOfRightSubArray < rightSubArray) {
		arr[indexOfMergedArray] = rightArray[indexOfRightSubArray];
		indexOfRightSubArray++;
		indexOfMergedArray++;
	}
}


