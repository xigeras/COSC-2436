
int getHeight(node *n) {
    if (n == nullptr) return 0;

    return 1 + max(getHeight(n->left), getHeight(n->right));
}

int getRightSubtree(node *n) {
    if (n == nullptr || n->right == nullptr) { 
        return 0;
    }
    return getHeight(n->right);
}