void postOrder(node* root) {
    if (root == nullptr) return;

    stack<node*> s1, s2;
    s1.push(root);

    while (!s1.empty()) {
        node* curr = s1.top();
        s1.pop();
        s2.push(curr);

        if (curr->left) s1.push(curr->left);
        if (curr->right) s1.push(curr->right);
    }

    while (!s2.empty()) {
        cout << s2.top()->data << " ";
        s2.pop();
    }
}