// Write a function to count number of nodes in a tree. How to do recursively?
// Are we required to traverse the whole tree? yes


#include <iostream>
using namespace std;

void inOrderTraversal(node* curr){
    if (curr != 0) {
        inOrderTraversal(curr->left);
        cout << curr->val;
        inOrderTraversal(curr->right);
    }
}

int count(node* curr) {
    if (curr == 0) {
        return 0;
    } else {
        return 1 + count(curr->left) + count(curr->right);
    }
}

