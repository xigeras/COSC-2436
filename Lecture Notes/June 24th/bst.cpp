#include "bst.h"
#include <iostream>
using namespace std;

void BST::insert(Node* curr, int x) {
    if (curr == nullptr) {
        Node *tmp = new Node(x);
        curr = tmp;
    } else {// go right or left 
        if (x < curr->val) {
            insert(cu->left, x);
        } else if (x > curr->val) {
            insert(curr->right, x);
        } else {
            cout << "x already exists.";
            return;
        }
    }
}

bool BST::search(Node* curr, int key) {
    if (curr == nullptr) return false;
    
    if (curr->val == key) {
        return true;
    } else {
        if (key < curr->val) {
            search(curr->left, key);
        }
        else {
            search(curr->right, key);
        }
    }
}
bool delete(Node* curr, int key) {
    Node* tmp = search(curr, key);
    if (tmp == nullptr) return false; // delete wasn't successful
    if (tmp->left == 0 && tmp->right == 0){
        Node* mark = tmp;
        // empty
        delete mark;
    } else if (tmp->left == 0 || tmp->right == 0) {
        if (tmp->left == 0) {
            swap with temp->right
            delete(swapped)
        } else {
            swap with tmp->left
            delete(swapped)
        }
        delete(swapped)
    } else {
        swap min of right
        delete
    }
}

Node* findMin(Node* curr) {
    if (curr->left == nullptr) {
        return curr;
    } else {
        findMin(curr->left);
    }
}
// find max
Node* findMax(Node* curr) {
    if (curr->right == nullptr) {
        return cu;
    } else { 
        findMax(curr->right);
    }
}

int main() {

    
    return 0;
}