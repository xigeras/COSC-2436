#include <iostream>
using namespace std;

struct Node{
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

class LinkedListQueue{
    private:
        Node* front;
        Node* rear;
        int count;
    public:
        LinkedListQueue() {
            front = nullptr;
            rear = nullptr;
            count = 0;
        }
        ~LinkedListQueue() {
            while (!isEmpty()) dequeue;
        }
        void enqueue(int item) {
            Node* newNode = new Node(item);

            if (isEmpty()) {
                front = rear = newNode;
            } else {
                rear->next = newNode;
                rear = newNode;
            }
            count++;
        }
        void dequeue() {
            if (isEmpty()) {
                cout << "Queue underflow, nothing to dequeue.\n";
                return;
            }
            Node* tmp = front;
            front = front->next;

            if (front == nullptr) {
                rear = nullptr;
            }
            delete tmp;
            count--;
        }
        int peek(){
            if(isEmpty()) {
                throw underflow_error("Queue is empty.");
            }
            return front->data;
        }
        bool isEmpty() {
            return (front == nullptr)
        }
        int size() {
            return count;
        }
};
