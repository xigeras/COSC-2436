node* search(node* root, int target) {
    if (root == nullptr || root->data == target) {
        return root;
    }

    if (target > root->data) {
        return search(root->right, target);
    }

    return search(root->left, target);
}