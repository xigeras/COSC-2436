void treeBFS(node* root) {
    if (root == nullptr) return;

    queue<node*> q;
    q.push(root);

    while(!q.empty()) {
        node* curr = q.front();
        q.pop();
        cout << curr->value << " ";
        if (curr->left) q.push(curr->left);
        if (curr->right) q.push(curr->right);
    }
}