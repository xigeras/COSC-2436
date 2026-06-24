#include <iostream>

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
        bool isEmpty();
        void insert(Node *curr, int x);
        bool search(Node *curr, int key);
        void inorderTraversal(Node *);
        void delete(Node *curr, int &x);
};