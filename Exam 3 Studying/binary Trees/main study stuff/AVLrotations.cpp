
int height(node *n) {
    if (n == nullptr) return 0;
    return n->height;
}

node *rotateLeft(node *root) {
    node *y = root->right;
    node *T2 = y->left;

    y->left = root;
    root->right = T2;

    root->height = 1 + max(height(root->left), height(root->right));
    y->height = 1 + max(height(y->left), height(y->right));

    return y;
};

node *rotateRight(node *root) {
    node *x = root->left;
    node *T2 = x->right;

    x->right = root;
    root->left = T2;

    root->height = 1 + max(height(root->left), height(root->right));
    x->height = 1 + max(height(x->left), height(x->right));

    return x;
}

node *rotateLeftRight(node *root) {
    root->left = rotateLeft(root->left);
    return rotateRight(root);
}

node *rotateRightLeft(node *root) {
    root->right = rotateRight(root->right);
    return rotateLeft(root);
}