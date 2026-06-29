#ifndef AVL_H
#define AVL_H

struct Node{
    int data;
    Node* left;
    Node* right;
    int height;

    Node(int value) : data(value), left(nullptr), right(nullptr), height(1) {}
};

class AVL{
    private:
        Node* root;

        int height(Node* curr);
        int getBalance(Node* curr);
        Node* rotateRight(Node* y);
        Node* rotateLeft(Node* x);
        Node* insert(Node* curr, int value);
        void preOrder(Node* curr);
        void inOrder(Node* curr);
        void postOrder(Node* curr);
        void levelOrder(Node* curr);
        void destroy(Node* curr);
    public:
        AVL();
        ~AVL();

        void insert(int value);
        void preOrder();
        void inOrder();
        void postOrder();
        void levelOrder();
};

#endif