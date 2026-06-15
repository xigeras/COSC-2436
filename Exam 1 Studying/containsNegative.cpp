#include <iostream>

using namespace std;

struct Node{
    int val;
    Node* next;
    Node* prev;
};

bool containsNegative(Node* head) {
    if (!head) return false;

    Node *curr = head;
    do {
        if(curr->val  < 0) return true;
    } while ((curr = curr->next) != head);
    return false;
}
