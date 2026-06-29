// SHELL SORT
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




// MERGESORT as a LL


Node* mergeLists(Node* l1, Node* l2) {
    if (!l1) return l2;
    if (!l2) return l1;

    if (l1->val < l2->val) {
        l1->next = mergeLists(l1->next, l2);
        return l1;
    } else {
        l2->next = mergeLists(l1, l2->next);
        return l2;
    }
}

Node* getMiddle(Node* head) {
    Node* slow = head;
    Node* fast = head->next;

    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

Node* mergeSortLL(Node* head) {
    if (!head || !head->next) return head;

    Node* mid = getMiddle(head);
    Node* rightHalf = mid->next;
    mid->next = nullptr;

    Node* leftSorted = mergeSortLL(head);
    Node* rightSorted = mergeSortLL(rightHalf);

    return mergeLists(leftSorted, rightSorted);
}

