int maxDepth(node* root) {
    if (!root) return 0;

    int leftDepth = maxDepth(node->left);
    int rightDepth = maxDepth(node->right);
    return max(leftDepth, rightDepth) + 1;
}