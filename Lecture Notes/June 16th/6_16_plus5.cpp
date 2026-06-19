#include <iostream>
using namespace std;
// write a function to find out if expression is balance

class Stack{
    private:
        int* arr;
        int top;
    public: 
        Stack(int size) {
            top = -1;
            arr = new int[size];
        }
        ~Stack() { delete[] arr;}
        void push(int x) {
            arr[++top] = x;
        }
        int pop() {
            if (top >= 0) {
                return arr[top--];
            }
            return 0;
        }
        int peek() {
            if (top >= 0) return arr[top];
            return 0;
        }
        bool isEmpty() {
            return top == -1;
        }
}

int pos(char x[], int n, char readchar) {
    for (int i = 0; i < n; i++) {
        if (x[i] == readchar) return i;
    }
    return -1;
}

int priority(char x) {
    if (x == '^') {
        return 4;
    }
    if (x == '*' || x == '/') {
        return 3; 
    }
    if (x == '+' || x == '-') {
        return 2; 
    }
    return 0;
}

bool isBalanced(char *sent){ 
    char open[3] = {'(','[', '{'};
    char closed[3] = {')',']','}'};

    int len = 0;
    while (sent[len] != '\0') {
        len++;
    }

    Stack s(len);

    for (int i = 0; i < len; i++ ) {
        char readchar = sent[i];

        if (pos(open, 3, readchar) != -1) {
            s.push(readchar);
        } else if (pos(closed, 3, readchar) != -1) {
            if (s.isEmpty()) return false;
            char top = (char)s.peek();
            
            if (pos(open, 3, top) == pos(closed, 3, readchar)) {
                s.pop();
            } else {
                return false;
            }
        }
    }

    return s.isEmpty();
}

string infixToPostfix(string infix) {
    Stack s(infix.length());
    string postfix = "";

    for (char ch : infix) {
        if (isspace(ch)) continue;

        if (isalnum(ch)) postfix += ch;
        else if (ch == '(') s.push(ch);
        else if (ch == ')') {
            while ((char)s.peek() != '(') postfix += (char)s.pop();
            s.pop();
        } else {
            while (!s.isEmpty() && priority((char)s.peek()) >= priority(ch)) {
                postfix += (char)s.pop();
            }
            s.push(ch);
        }
    }

    while (!s.isEmpty()) postfix += (char)s.pop();
    return postfix;
}

int evaluatePostfix(string postfix) {
    Stack s(postfix.length());

    for 
}

int main() {


    return 0;
}

// menu
// 1 - read an infix
// 2 - convert to postfix
// 3 - evaluate postfix
// 4 - isBalanced?
// 5 - exit


/*
write a menu program to test stack

...............while loop do you want to continue 

1- read an expression based on the type of the expression 

menu

1- convert infix to postfix   ... use a stack of char

2- evaluate a postfix  .... stack of int

3-isbalanced    stack of char

4 - exit 
enter your choice 
*/