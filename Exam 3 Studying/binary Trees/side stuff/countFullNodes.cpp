int countFullNodes(Node* curr) {
    if (curr == nullptr) return 0;
    if (curr->left != nullptr &&  curr->right != nullptr) {
        return 1 + countFullNodes(curr->left) + countFullNodes(curr->right);
    }
    return countFullNodes(curr->left) + countFullNodes(curr->right);
}