#include "avl.h"
#include <iostream>
#include <algorithm>
using namespace std;

AVL::AVL() : root(nullptr) {}
AVL::~AVL() { destroy(root); }

void AVL::destroy(Node* curr) {
    if (curr) {
        destroy(curr->left);
        destroy(curr->right);
        delete curr;
    }
}

int AVL::height(Node* curr) {
    return curr ? curr->height : 0;
}

int AVL:getBalance(Node* curr) {
    return curr ? height(curr->left) - height(curr->right) : 0;
}

Node* AVL::rotateRight(Node* y) {
    Node* x = y->left;
    Node* z = x->right;

    x->right = y;
    y->left = z;

    y->height = max(height(y->left), height(y->right)) + 1;
    x->height = max(height(x->left), height(x->right)) + 1;

    return x;
}

Node* AVL::rotateLeft(Node* x) {
    Node* y = x->right;
    Node* z = y->left;

    y->left = x;
    x->right = z;

    x->height = max(height(x->left), height(x->right)) + 1;
    y->height = max(height(y->left), height(y->right)) + 1;

    return y;
}

Node* AVL::insert(Node* curr, int value) {
    if (!curr) return new Node(value);

    if (value < curr->data) {
        curr->left = insert(curr->left, value);
    } else if (value > curr->data) {
        curr->right = insert(curr->right, value);
    } else {
        return curr;
    }

    curr->height = 1 + max(height(curr->left), height(curr->right));
    int balance = getBalance(curr);

    if (balance > 1 && value < curr->left->data) {
        return rotateRight(curr);
    } else if (balance < -1 && value > curr->right->data) {
        return rotateLeft(curr);
    } else if (balance > 1 && value > curr->left->data) {
        curr->left = rotateLeft(curr->left);
        return rotateRight(curr);
    } else if (balance < -1 && value < curr->right->data) {
        curr->right = rotateRight(curr->right);
        return rotateLeft(curr);
    }

    return curr;
}


void AVL::preOrder(Node* curr) {
    if (!curr) return;

    cout << curr->data << " ";
    preOrder(curr->left);
    preOrder(curr->right);
}

void AVL::inOrder(Node* curr) {
    if (!curr) return;

    inOrder(curr->left);
    cout << curr->data << " ";
    inOrder(curr->right);
}

void AVL::postOrder(Node* curr) {
    if (!curr) return;

    postOrder(curr->left);
    postOrder(curr->right);
    cout << curr->data << " ";
}

void AVL::levelOrder(Node* curr) {
    if (!curr) return;

    queue<Node*> q;
    q.push(root);

    while(!q.empty()) {
        Node* n = q.front();
        q.pop();
        cout << n->data << " ";

        if (n->left) q.push(n->left);
        if (n->right) q.push(n->right);
    }
}









void AVL::insert(int value) {
    root = insert(root, value);
}

void AVL::preOrder() {
    preOrder(root);
    cout << endl;
}

void AVL::inOrder() {
    inOrder(root);
    cout << endl;
}

void AVL::postOrder() {
    postOrder(root);
    cout << endl;
}

void AVL::levelOrder() {
    levelOrder(root);
    cout << endl;
}