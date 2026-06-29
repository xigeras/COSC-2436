bool isInverse(node* root1, node* root2) {
    if (root1 == nullptr && root2 == nullptr) {
        return true;
    }

    if (root1 == nullptr || root2 == nullptr) {
        return false;
    }

    return (root1->data == root2->data) && isInverse(root1->left, root2->right) && isInverse(root1->right, root2->left);
}