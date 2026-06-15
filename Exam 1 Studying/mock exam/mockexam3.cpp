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
    return smallest
}