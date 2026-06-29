bool isSubtree(node* rootA, node* rootB) {
    if (!rootB) return true;
    if (!rootA) return false;

    if (isEqual(rootA, rootB)) return true;

    return isSubtree(rootA->leftchild, rootB) || isSubtree(rootA->rightchild, rootB);
}

bool isEqual(node* rootA, node* rootB) {
    if (!rootA && !rootB) return true;
    if (!rootA || !rootB) return false;
    return (rootA->data == rootB->data) & isEqual(rootA->leftchild, rootB->leftchild) && isEqual(rootA->rightchild, rootB->rightchild);  
}