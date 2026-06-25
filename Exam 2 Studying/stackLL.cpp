#include <iostream>
using namespace std;

struct Node{
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

class StackLL{
    private:
        Node* topNode;
    public: 
        StackLL();
        bool isEmpty() {

        }
        void push(int val) {
            Node* tmp = new Node(val);
            tmp->next = topNode;
            topNode = tmp;
        }
        void pop() {
            if (topNode == nullptr) {
                return;
            }
            Node *tmp = topNode;
            topNode = topNode->next;
            delete tmp;
        }
}