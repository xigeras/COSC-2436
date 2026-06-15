#include <iostream>

struct Node{
    int val;
    Node* next;
    Node* prev;
    Node(int val) : value(val), prev(nullptr), next(nullptr) {};
};

class doublyList{
    private:
        Node* head;
        Node* tail;
    public:
        doublyList();
        void insertAtHead(int d) {
            Node *tmp = new Node(d);
            if (head == nullptr) {
                head = tmp;
                return;
            }
            tmp->next = head;
            head->prev = tmp;
            head = tmp;
        }
        void insertAtTail(int d) {
            Node *tmp = new Node(d);
            if (head == nullptr) {
                head = tmp;
                return;
            }
            Node *cur = head;
            while (cur->next != nullptr) {
                cur = cur->next;
            }
            cur->next = tmp;
            tmp->prev = cur;
        }
        void insertAtIndex(int index, int d) {
            if (d <= 0) {
                insertAtHead(d);
                return;
            }
            else if (d >= getSize()) {
                insertAtTail(d);
                return;
            } 

            Node *cur = head;
            for (int i = 0; i < index - 1; i++) {
                cur = cur->next;
            }
            Node *tmp = new Node(d);
            tmp->next = cur->next;
            cur->next = tmp;
            tmp->prev = cur;
            tmp->next->prev = tmp;
        }
        void removeHead() {
            if (head == nullptr)
                return;
            else if (head->next == nullptr) {
                removeHead();
                return;
            }
            
            Node *tmp = head;
            head = head->next;
            delete tmp;
            if (head != nullptr) 
                head->prev = nullptr;
            return head;
        }
        void removeTail() {
            if (head == nullptr)
                return;

            Node *cur = head;
            Node *prev = nullptr;
            //iterate cur until cur->next==nullptr. iterate prev with it
            while (cur->next != nullptr) {
                prev = cur;
                cur = cur->next;
            }
            prev->next = nullptr;
            delete cur;
            return head;
        }
        void removeAtPos() {
            if (head == nullptr)
                return;
            else if (pos == 0) {
                removeAtHead();
                return;
            }

            Node* cur = head;
            Node* prev = nullptr;

            //loop
            for (int i = 0; i < pos; i++) {
                if (cur == nullptr)
                    return;
                prev = cur;
                cur = cur->next;
            }

            if (cur == nullptr)
                return;
            else if (cur->next != nullptr)
                cur->next->prev = prev;
            prev->next = cur->next;
            delete cur;


            
        }

}