bool getPath(TreeNode* root, int B, vector<int> &res) {
    if (root == nullptr) return false;

    res.push_back(root->val);

    if (root->val == B) return true;

    if (getPath(root->left, B, res) || getPath(root->right, B, res)) return true;

    res.pop_back();
    return false;
}

vector<int> Solution::solve(TreeNode* A, int B) {
    vector<int> res;
    getPath(A, B, res);
    return res;
}

// T.C -> O(n), S.C -> O(h)
