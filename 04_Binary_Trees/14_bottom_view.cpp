vector<int> bottomView(BinaryTreeNode<int> * root) {
    vector<int> res;
    if (root == NULL) return res;
    queue<pair<BinaryTreeNode<int> *, int>> q;  // (Node, currLine)
    map<int, int> mp;        // (currLine, nodeVal)

    q.push({root, 0});
    while (!q.empty()) {
        auto pr = q.front();
        q.pop();
        BinaryTreeNode<int> *currNode = pr.first;
        int currLine = pr.second;

        // Let it update everytime. The one node on same line that updates the last will be the answer finally.
        mp[currLine] = currNode->data;

        if (currNode->left) q.push({currNode->left, currLine - 1});
        if (currNode->right) q.push({currNode->right, currLine + 1});
    }

    for (auto pr : mp) {
        res.push_back(pr.second);
    }

    return res;
}