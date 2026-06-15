#include <iostream>

using namespace std;

/*
Prompt: Write a C++ function int sumEvens(Node* head) that 
traverses a singly linked list and returns the sum of all 
the even numbers. If the list is empty, return 0.
(Assume Node has int data and Node* next)
*/

struct Node{
    int data;
    Node* next;
};

class LinkedList {
    private:
        Node* head;
    public: 
        LinkedList();
        void getHead() {
            return head;
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
        Node* reverseList(Node* head){
            ListNode* curr = head;
            ListNode* prev = nullptr;
            while (curr != nullptr) {
                ListNode* next = curr->next;
                curr->next = prev;
                prev = curr;
                curr = next;
            }
            return prev;
        }
        Node* middleNode(Node* head) {
            if (!head || head->next == nullptr) {
                return head;
            }
            if (head->next->next == nullptr)
                return head->next;
            
            Node* fast = head;
            Node* slow = head;

            while (fast != nullptr && fast->next != nullptr) {
                slow = slow->next;
                fast = fast->next->next;
            }
            return slow;
        }
        Node* mergeTwoLists(Node* h1, Node* h2) {
            if (h1 == nullptr) { return h2; }
            if (h2 == nullptr) { return h1; }

            if (h1->val < h2->val) {
                h1->next = mergeTwoLists(h1->next, h2);
                return h1; 
            } else {
                h2->next = mergeTwoLists(h1, h2->next);
                return h2;
            }
        }
}
int main() {

}