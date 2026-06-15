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
            
            if (n %) // number % 2 == 0 validates eve
            
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
            
            ListNode* fast = head;
            ListNode* slow = head;

            while (fast != nullptr && fast->next != nullptr) {
                slow = slow->next;
                fast = fast->next->next;
            }
            return slow;
        }
}
int main() {

}