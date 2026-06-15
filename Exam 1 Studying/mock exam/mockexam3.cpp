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


ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if (list1 == nullptr) {
            return list2;
        }
        if (list2 == nullptr) {
            return list1;
        }

        if (list1->val < list2->val) {
            list1->next = mergeTwoLists(list1->next, list2);
            return list1;
        } else {
            list2->next = mergeTwoLists(list1, list2->next);
            return list2;
        }
    }


    bool isPalindrome(ListNode* head) {
        ListNode *slow = head, *fast = head, *prev, *temp;
        while (fast && fast->next)
            slow = slow->next, fast = fast->next->next;
        prev = slow, slow = slow->next, prev->next = NULL;
        while (slow)
            temp = slow->next, slow->next = prev, prev = slow, slow = temp;
        fast = head, slow = prev;
        while (slow)
            if (fast->val != slow->val) return false;
            else fast = fast->next, slow = slow->next;
        return true;
    }

ListNode* deleteDuplicates(ListNode* head) {
        if (head == nullptr)
            return head;

        ListNode* tmp = new ListNode(head->val);
        ListNode* tail = tmp;
        ListNode* curr = head->next;

        while (curr != nullptr) {
            if tail->val != curr->val) {
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