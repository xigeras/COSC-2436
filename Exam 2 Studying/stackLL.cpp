#include <iostream>
using namespace std;

struct Node{
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

class StackLL{
    private:
        Node* top;
    public:
        StackLL();
        void push(int val) {
            Node *tmp = new Node(val);
            tmp->next = top;
            top = tmp;
        }
        void pop() {
            if (top == nullptr) return;
            Node* tmp = top;
            top = top->next;
            delete tmp;
        }
}

