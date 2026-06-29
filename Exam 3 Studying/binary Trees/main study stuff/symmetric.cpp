bool isSymmetricHelper(Node* x, Node* y) {
    if (x == nullptr && y == nullptr) {
        return true;
    } else if (x == nullptr || y == nullptr) {
        return false;
    }

    return isSymmetricHelper(x->left, y->right) && isSymmetricHelper(x->right, y->left);
}

bool isSymmetric(Node* root) {
    if (root == nullptr) return true;

    return isSymmetricHelper(root->left, root->right);
}
