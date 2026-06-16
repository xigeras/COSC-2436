#include <iostream>

using namespace std;

struct node{
    int val;
    node *next
};

class sasll{
    private:
        node* top;
    public:
        sasll();
        void push(int x) {
            //1 - create
            //2 - fill
            //3 - update
        }
        void pop(int &retx) { // int pop();
            // 1- mark
            // 2- empty
            // 3 - update top
            // 4 - delete tmp

        }
        void print();
}

int main() {
    sasll myStack;
    myStack.push(11);
    myStack.push(22);
    myStack.push(69);
    myStack.print();
    myStack.pop();

}


// stack as LL
// stack as array
// stack in evaluating expressions

// infix (2+3), prefix(+23), postfix(23+)