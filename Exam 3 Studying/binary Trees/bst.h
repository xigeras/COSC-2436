#ifndef BST_H
#define BST_H

struct Node{
    Node *left;
    int val;
    Node *right;
    Node(int x) : val(x), left(nullptr), right(nullptr) {}
};

class BST{
    private:
        Node *root;
    public:
        BST();
        ~BST();

        bool isEmpty();
        void insert(Node *curr, int x);
        bool search(Node *curr, int key);
        void preOrder(Node *curr);
        void inOrder(Node *curr);
        void postOrder(Node *curr);
        void levelOrder(Node* curr);
        void delete(Node *curr);
};

#endif