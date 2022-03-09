// Approach: T.C -> O(n), S.C -> O(n)
#include<bits/stdc++.h>
vector<int> getTopView(TreeNode<int> *root) {
    vector<int> result;
    if (root == NULL) return result;

    queue<pair<TreeNode<int>*, int>> q;         // (node, currLine)
    map<int, int> mp;                // (currLine, nodeval)

    q.push({root, 0});
    while (!q.empty()) {
        auto pr = q.front();
        q.pop();
        TreeNode<int>* currNode = pr.first;
        int currLine = pr.second;

        if (mp.find(currLine) == mp.end()) {
            mp.insert({currLine, currNode->val});
        }

        if (currNode->left) q.push({currNode->left, currLine - 1});
        if (currNode->right) q.push({currNode->right, currLine + 1});
    }

    for (auto pr : mp) {
        result.push_back(pr.second);
    }

    return result;
}