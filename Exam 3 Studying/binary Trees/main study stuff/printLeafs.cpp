void printLeafs(node* root) {
    if (root) {
        printLefts(root->left);
        if (!root->left && !root->right) {
            cout << root->data << " ";
        }
        printLeafs(root->right);
    }
}