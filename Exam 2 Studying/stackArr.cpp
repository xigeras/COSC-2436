#include <iostream>
using namespace std;

class StackArr{
    private: 
        int* arr;
        int capacity;
        int top;
    public:
        StackArr() {
            arr = new int[capacity];
            top = -1;
        }
        void push(int val) {
            if (top == capacity - 1) {
                return;
            }
            arr[++top] = val;
        }
        void pop() {
            if (top == -1) {
                return;
            }
            top--;
        }
        void top() {
            if (top == -1) return -1;
            return arr[top];
        }
}