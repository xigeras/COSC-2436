
int lowestCommonAncestor(Node* root, Node* n1, Node* n2) {
    if (root == nullptr || n1 == nullptr || n2 == nullptr)
        return -1;

    if (n1->val < root->val && n2->val < root->val) 
        return lowestCommonAncestor(root->left, n1, n2);
    else if (n1->val > root->val && n2->val > root->val)
        return lowestCommonAncestor(root->right, n1, n2);
    
        return root->val;
}