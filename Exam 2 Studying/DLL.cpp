#include <iostream>
using namespace std;

struct Node {
    int val;
    Node* next;
    Node* prev;
    Node(int v) : val(v), prev(nullptr), next(nullptr) {}
};

class doublyList {
private:
    Node* head;
    Node* tail;
    int size;

public:
    doublyList() : head(nullptr), tail(nullptr), size(0) {}

    int getSize() { return size; }

    void insertAtHead(int d) {
        Node* tmp = new Node(d);
        if (head == nullptr) {
            head = tail = tmp;
        } else {
            tmp->next = head;
            head->prev = tmp;
            head = tmp;
        }
        size++;
    }

    void insertAtTail(int d) {
        Node* tmp = new Node(d);
        if (tail == nullptr) { // List is empty
            head = tail = tmp;
        } else {
            tail->next = tmp;
            tmp->prev = tail;
            tail = tmp; // Instantly update tail without a while loop!
        }
        size++;
    }

    void insertAtIndex(int index, int d) {
        if (index <= 0) {
            insertAtHead(d);
            return;
        }
        if (index >= size) {
            insertAtTail(d);
            return;
        }

        Node* cur = head;
        for (int i = 0; i < index - 1; i++) {
            cur = cur->next;
        }
        
        Node* tmp = new Node(d);
        tmp->next = cur->next;
        tmp->prev = cur;
        
        if (cur->next != nullptr) {
            cur->next->prev = tmp;
        }
        cur->next = tmp;
        size++;
    }

    void removeHead() {
        if (head == nullptr) return;

        Node* tmp = head;
        if (head == tail) { // Only one node in the list
            head = tail = nullptr;
        } else {
            head = head->next;
            head->prev = nullptr;
        }
        delete tmp;
        size--;
    }

    void removeTail() {
        if (tail == nullptr) return;

        Node* tmp = tail;
        if (head == tail) { // Only one node
            head = tail = nullptr;
        } else {
            tail = tail->prev;
            tail->next = nullptr;
        }
        delete tmp;
        size--;
    }

    void removeAtPos(int pos) {
        if (pos < 0 || pos >= size || head == nullptr) return;
        if (pos == 0) { removeHead(); return; }
        if (pos == size - 1) { removeTail(); return; }

        Node* cur = head;
        for (int i = 0; i < pos; i++) {
            cur = cur->next;
        }

        // Bridge the gap around cur
        cur->prev->next = cur->next;
        cur->next->prev = cur->prev;
        
        delete cur;
        size--;
    }

    void reverseList(Node*& head, Node*&tail) {
        if (head == nullptr || head->next == nullptr) {
            return;
        }

        Node* curr = head;
        Node* tmp = nullptr;

        while (curr != nullptr) {
            tmp = curr->prev;
            curr->prev = curr->next;
            curr->next = tmp;

            curr = curr->prev;
        }
        tail = head;
        head = tmp->prev;
    }

    bool contains(int target) {
        Node* curr = head;

        while (curr != nullptr) {
            if (curr->val == target) {
                return true;
            }
            curr = curr->next;
        }
        return false;
    }
};