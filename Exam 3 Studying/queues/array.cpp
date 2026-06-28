#include <iostream>
using namespace std;

class Queue{
    private:
        int* arr;
        int capacity;
        int front;
        int rear;
        int count;
    public:
        Queue(int size = 10) {
            capacity = size;
            arr = new int[capacity];
            front = 0;
            rear = -1;
            count = 0;
        }
        ~Queue() { delete[] arr; }
        void enqueue(int item) {
            if (isFull()) {
                cout << "Queue Overflow, cannot enqueue " << item << ".\n";
                return;
            }
            rear = (rear + 1) % capacity;
            arr[rear] = item;
            count++;
        }
        void dequeue() {
            if (isEmpty()) {
                cout << "Queue underflow, nothing to dequeue.\n";
                return;
            }
            front = (front + 1) % capacity;
            count--;
        }
        int peek() {
            if (isEmpty()) {
                throw underflow_error("Queue is empty.");
            }
            return arr[front];
        }
        bool isEmpty() {
            return (count == 0);
        }
        bool isFull() {
            return (count == capacity);
        }
};