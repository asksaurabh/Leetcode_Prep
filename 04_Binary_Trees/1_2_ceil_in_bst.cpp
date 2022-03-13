// Approach 1: Recursive
void getCeil(BinaryTreeNode<int> *root, int key, int &res) {
    if (root == nullptr) return;

    if (root->data == key) {
        res = root->data;
        return;
    }

    else if (root->data > key) {
        // Possible answer
        res = root->data;
        getCeil(root->left, key, res);
    }

    else
        getCeil(root->right, key, res);
}
int findCeil(BinaryTreeNode<int> *node, int x) {
    int res = INT_MAX;
    getCeil(node, x, res);
    return res == INT_MAX ? -1 : res;
}

// Approach 2: Iterative.
int findCeil(BinaryTreeNode<int> *root, int key) {
    int ceil = -1;
    while (root) {
        if (root->data == key) return root->data;
        else if (root->data > key) {
            // possible answer
            ceil = root->data;
            root = root->left;
        } else {
            root = root->right;
        }
    }

    return ceil;
}