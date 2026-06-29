#include "bst.h"
#include <iostream>
#include <queue>
using namespace std;

BST::BST() : root(nullptr) {}

BST::~BST() { destroy(root); }

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
bool BST::delete(Node* curr, int key) {
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

void BST::preOrder(Node* curr) {
    if (curr == nullptr) return;

    cout << curr->value << " " << endl;
    preOrder(curr->left);
    preOrder(curr->right);
}

void BST::inOrder(Node* curr) {
    if (curr == nullptr) return;

    inOrder(curr->left);
    cout << curr->value << " " << endl;
    inOrder(curr->right);
}

void BST::postOrder(Node* curr) {
    if (curr == nullptr) return;

    postOrder(curr->left);
    postOrder(curr->right);
    cout << curr->value << " " << endl;
}

void BST::levelOrder(Node* curr) {
    if (!curr) return;

    queue<Node*> q;
    q.push(root);

    while (!q.empty()) {
        Node* n = q.front();
        q.pop();
        cout << n->data << " ";

        if (n->left) {
            q.push(n->left);
        } if (n->right) {
            q.push(n->right);
        }
    }
}

int main() {

    
    return 0;
}