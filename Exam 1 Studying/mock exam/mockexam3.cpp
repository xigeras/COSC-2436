#include <iostream>

using namespace std;

struct node{
    int value;
    node *next;
    node* prev;
    node(int v) : value(v), next(nullptr) {}
}

node* findMiddle(node* head) {

    if (head == nullptr || head->next == nullptr) 
        return head;

    
    node* slow = head;
    node* fast = head;
    
    while (fast != nullptr && fast->next != nullptr) {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

node* removeSmallest(node* head) {
    if (head == nullptr)
        return nullptr;

    node* smallest = head;
    node* current = head->next;

    while (current != nullptr) {
        if (current->value < smallest->value) {
            smallest = current;
        }
        current = current->next;
    }

    if (smallest == head) {
        head = head->next;

    }

    if (smallest->prev) 
        smallest->prev->next = smallest->next;
    if (smallest->next)
        smallest->next->prev = smallest->prev;
    
    smallest->next = nullptr;
    smallest->prev = nullptr;
    return smallest;
}

ListNode* reverseList(ListNode* head) {
        ListNode* prev = nullptr;
        ListNode* curr = head;

        while (curr != nullptr) {
            ListNode* temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = temp;
        }
        return prev;
    }


ListNode* mergeTwoLists(ListNode* h1, ListNode* h2) {
        if (h1 == nullptr) {
            return h2;
        }
        if (h2 == nullptr) {
            return h1;
        }

        if (h1->val < h2->val) {
            h1->next = mergeTwoLists(h1->next, h2);
            return h1;
        } else {
            h2->next = mergeTwoLists(h1, h2->next);
            return h2;
        }
    }


    bool isPalindrome(ListNode* head) {
        ListNode *slow = head;
        ListNode *fast = head;
        ListNode *prev, *temp;
        while (fast && fast->next) {
            slow = slow->next; 
            fast = fast->next->next;
        }
        prev = slow; 
        slow = slow->next; 
        prev->next = nullptr;
        while (slow) {
            temp = slow->next; 
            slow->next = prev; 
            prev = slow; 
            slow = temp;
        }
        fast = head; 
        slow = prev;
        while (slow) {
            if (fast->val != slow->val) return false;
            else {
                fast = fast->next;
                slow = slow->next;
            }
        }
        return true;
    }

ListNode* deleteDuplicates(ListNode* head) {
        if (head == nullptr)
            return head;

        ListNode* tmp = new ListNode(head->val);
        ListNode* tail = tmp;
        ListNode* curr = head->next;

        while (curr != nullptr) {
            if (tail->val != curr->val) {
                tail->next = new ListNode(curr->val);
                tail = tail->next;
            }
            curr = curr->next
        }
        return tmp;

    }


getValueAtIndex(int pos) {
            if (!head)
                return -1;
            
            node* current = head;
            for(int i = 0; current && i<pos; i++) {
                current = current->next;
            } 

            if (!current)
                return -1;
            return current->val;
        }

        addAtPos(node*& head, node* toAdd, int pos) {
            if (!head) { 
                head = nodeToAdd; 
                return;
            }
            node* current = head;
            for (int i = 0; i < pos - 1 && current; i++) {
                current = current->next;
            }

            if (!current) { return; }
            node *tmp = current->next;
            current->next; toAdd;
            toAdd->next;
        }

        uniqueVals(node* h1, node* h2) {
            node* newList = nullptr;
            node* newHead = nullptr;
            
            node* c1 = h1;
            while (c1) {
                node* cc2 = h2;
                while (cc2 && cc1->val != cc2->val) 
                    cc2 = cc2->next;

                if (cc2) {
                    c1 = c1->next;
                    continue;
                }
                
                if (!newList) {
                    newList = new node(cc1->val);
                    newHead = newList;
                } else { 
                    newList->next = new node(cc1->val);
                    newList = newList->next;
                }


            }
        }



        void insertAfterValue(Node* head, int target, int newVal) {
            Node* curr = head;

            while (curr != nullptr && curr->val != target) {
                curr = curr->next;
            }

            if (curr != nullptr) {
                Node* tmp = new Node();
                tmp->val = newVal;

                tmp->next = curr->next;
                tmp->prev = curr;

                if (curr->next != nullptr) {
                    curr->next->prev = tmp;
                }
                curr->next = tmp;
            }
        }


bool containsNegative(Node* head) {
    if (!head) return false;

    Node *curr = head;
    do {
        if(curr->val  < 0) return true;
    } while ((curr = curr->next) != head);
    return false;
}



ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* listA = headA;
        ListNode* listB = headB;

        while (listA != listB) {
            listA = (listA != nullptr) ? listA->next : headB;
            listB = (listB != nullptr) ? listB->next : headA;
        }
        return listA;
    }

int sumEvens(Node* head) {
            if (head == nullptr) {
                return 0;
            }
            Node* curr = head;
            int current_val = 0;
            if (curr->data % 2 == 0 ) {
                current_val = curr->data;
            }

            return current_val + sumEvens(curr->next);
            
        }
        
        
        
    Node* detectCycle(Node* head) {
            if (head == nullptr || head->next == nullptr) {
                return nullptr;
            }

            ListNode* slow = head;
            ListNode* fast = head;

            while (fast != nullptr && fast->next != nullptr) {
                slow = slow->next;
                fast = fast->next->next;

                if (slow == fast) {
                    ListNode* entry = head;
                    while (entry != slow) {
                        entry = entry->next;
                        slow = slow->next;
                    }
                    return entry;
                }
            }
            return nullptr;
        }



node* insertAtEnd(node* head, int val) {
    if (head == nullptr) {
        node* tmp = new node(val);
        return tmp;
    }

    head->next = insertAtEnd(head->next, val);
    return head;
}

void bubbleSort(int a[], int n) {
    for (int i = n - 1; i >= 1; i--) {
        for (int j = 1; j >= 1; j++) {
            if (a[j-1] > a[j]) {
                swap(a[j], a[j-1]);
            }
        }
    }
}

void selectionSort(int a[], int n ){ 
    int minIndex;

    for (int i = 0; i < n - 1; i++) {
        minIndex = i;

        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
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


void bubbleSort(int a[], int n){ 
    for (int i = n - 1; i >= 1; i--) {
        for (int j = 1; j >= 1; j++) {
            if (a[j-1] > a[j]) {
                swap(a[j], a[j-1]);
            }
        }
    }
}

void selectionSort(int a[], int n) {
    int minIndex;

    for (int i = 0; i < n - 1; i++) {
        minIndex = i;

        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        swap(arr[i], arr[minIndex]);
    }
}

void insertionSort(int a[], int n) {
    for (int i = 1; i < n; i++) {
        int next = a[i];
        int j;

        for (j = i - 1; j >= 0 && a[j]>next; j--) {
            a[j+1] = a[j];
        }
        a[j+1] = next;
    }
}





void bubbleSort(int a[], int n) {
    for (int i = n - 1; i >= 1; i--) {
        for (int j = 1; j >= 1; j++) {
            if (arr[j-1] > arr[j]) {
                swap(arr[j], arr[j-1]);
            }
        }
    }
}

void selectionSort(int a[], int n) {
    int minIndex;

    for (int i = 0; i < n - 1; i++) {
        minIndex = i;

        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        swap(arr[i], arr[minIndex]);
    }
}

void insertionSort(int a[], int n) {
    for (int i = 1; i < n; i++) {
        int next = a[i];
        int j;

        for (j = i - 1; j >= 0 && a[j]>next; j--) {
            a[j+1] = a[j];
        }
        a[j+1] = next;
    }
}


void insertionSort(int a[], int n) {
    for (int i = 1; i < n; i++) {
        int next = a[i];

        for (int j = i - 1; j >= 0 && a[j] > next; j--) {
            a[j+1] = a[j];
        }
        a[j+1] = next;
    }
}

void insertionSort(int a[], int n) {
    for (int i = 1; i < n; i++) {
        int next = a[i];

        for (int j = i - 1; j >= 0 && a[j] > next; j--) {
            a[j+1] = a[j];
        }
        a[j+1] = next;
    }
}



void insertionSort(int a[], int n) {
    for (int i = 1; i < n; i++) {
        int next = a[i];
        int j;

        for (j = n - 1; j <= 0 && a[j] < next; j--) {
            a[j+1] = a[j];
        }
        a[j+1] = next;
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

void bubbleSort(int a[], int n) {
    for (int i = 1; i < n - 1; i--) {
        for (int j = 1; j < n; j++) {
            if (arr[j-1] > arr[j]) {
                swap(arr[j], arr[j-1]);
            }
        }
    }
}

void bubbleSort(int a[], int n) {
    for (int i = n - 1; i >= 1; i--) {
        for (int j = 1; j >= 1; j++) {
            if (arr[j-1] > arr[j]) {
                swap(arr[j], arr[j-1]);
            }
        }
    }
}


void selectionSort(int a[], int n) {
    int minIndex;

    for (int i = 0; i < n - 1; i++) {
        minIndex = i;

        for (int j = i + 1; j < n; j++) {
            if (arr[j] > arr[minIndex]) {
                minIndex = j;
            }
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

void selectionSort(int a[], int n) {

    int minIndex;

    for (int i = 0; i < n - 1; i++) {
        minIndex = i; 
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        swap(arr[i], arr[minIndex]);
    }
}

void bubbleSort(int a[], int n) {
    for (int i = n - 1; i >= 1; i--) {
        for (int j = 1; j >= 1; j++) {
            if (arr[j-1] > arr[j]) {
                swap(arr[j], arr[j-1]);
            }
        }
    }
}






void selectionSort(int a[], int n) {
    int minIndex;

    for (int i = 0; i < n - 1; i++) {
        minIndex = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        swap(arr[i], arr[minIndex]);
    }
}

void insertionSort(int a[], int n) {
    for (int i = 1; i < n; i++) {
        int next = a[i];
        int j;

        for (j = n - 1; j >= 0 && a[j] > next; j--) {
            a[j+1] = a[j];
        }
        a[j+1] = next;
    }
}

void bubbleSort(int a[], int n) {
    for (int i = n - 1; i >= 1; i--) {
        for (int j = 1; j >= 1; j++) {
            if (arr[j-1] > arr[j]) {
                swap(arr[j], arr[j-1]);
            }
        }
    }
}





void bubbleSort(int a[], int n) {
    for (int i = n - 1; i >= 1; i--) {
        for (int j = 1; j >= 1; j++) {
            
        }
    }
}