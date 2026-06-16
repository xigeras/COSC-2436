#include <iostream>

using namespace std;

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
}



// TO DO 
// prefix to infix
// infix to postfix
// postfix to prefix
// infix to prefix
// postfix to infix
// prefix to postfix
