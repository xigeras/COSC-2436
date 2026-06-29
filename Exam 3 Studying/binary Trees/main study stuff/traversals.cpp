void inOrder(node* node) {
    if (node == nullptr) return;

    inOrder(node->left);
    cout << node->value << " " << endl;
    inOrder(node->right);
}

void preOrder(node* node) {
    if (node == nullptr) return;

    cout << node->value << " " << endl;
    preOrder(node->left);
    preOrder(node->right);
}

void postOrder(node* node) {
    if (node == nullptr) return;
    
    preOrder(node->left);
    preOrder(node->right);
    cout << node->value << " " << endl;
}


void levelOrder(node* node) {
    if (!node) return;

    queue<Node*> q;
    q.push(root);

    while (!q.empty()) {
        Node* n = q.front();
        q.pop();
        cout << n->data << " ";

        if (n->left)
            q.push(n->left);
        if (n->right) 
            q.push(n->right);
    }
}