void preOrder(BinaryTreeNode<int> *root, int level, int &nodesPrinted) {
    if (root == nullptr) return;

    if (nodesPrinted < level) {
        // Coming at this level for the first time
        cout << root->data << " ";
        nodesPrinted++;
    }

    preOrder(root->left, level + 1, nodesPrinted);
    preOrder(root->right, level + 1, nodesPrinted);
}
void printLeftView(BinaryTreeNode<int> *root)
{
    int nodesPrinted = 0;
    preOrder(root, 1, nodesPrinted);
}