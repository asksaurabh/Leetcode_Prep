#include<bits/stdc++.h>
// T.C -> O(n), S.C -> O(n)

// Find a node with value 'start' in a binary tree
BinaryTreeNode<int>* findNode(BinaryTreeNode<int>* root, int start) {
    if (root == nullptr) return root;

    if (root->data == start) return root;
    BinaryTreeNode<int>* node = findNode(root->left, start);
    if (node) return node;

    return findNode(root->right, start);
}
void getParent(BinaryTreeNode<int>* root, map<BinaryTreeNode<int>*, BinaryTreeNode<int>*> &parent) {
    queue<BinaryTreeNode<int>*> q;
    q.push(root);

    while (!q.empty()) {
        BinaryTreeNode<int>* currNode = q.front();
        q.pop();

        if (currNode->left) {
            parent[currNode->left] = currNode;
            q.push(currNode->left);
        }
        if (currNode->right) {
            parent[currNode->right] = currNode;
            q.push(currNode->right);
        }
    }
}

int timeToBurnTree(BinaryTreeNode<int>* root, int start)
{
    if (root == nullptr) return 0;
    // Get me to the start node.(Assuming it exists in the tree)
    BinaryTreeNode<int>* st = findNode(root, start);

    // Link all the nodes to there parents to apply bfs
    map<BinaryTreeNode<int>*, BinaryTreeNode<int>*> parent;
    getParent(root, parent);

    // Apply bfs to reach all the nodes starting from st.
    map<BinaryTreeNode<int>*, int> visited;
    queue<BinaryTreeNode<int>*> q;
    q.push(st);
    visited[st] = 1;

    int time = 0;
    while (!q.empty()) {
        int size = q.size();
        int burntSomeone = 0;

        for (int i = 0; i < size; i++) {
            BinaryTreeNode<int>* currNode = q.front();
            q.pop();

            if (currNode->left and !visited[currNode->left]) {
                burntSomeone = 1;
                q.push(currNode->left);
                visited[currNode->left] = 1;
            }
            if (currNode->right and !visited[currNode->right]) {
                burntSomeone = 1;
                q.push(currNode->right);
                visited[currNode->right] = 1;
            }
            if (parent[currNode] and !visited[parent[currNode]]) {
                burntSomeone = 1;
                q.push(parent[currNode]);
                visited[parent[currNode]] = 1;
            }
        }

        if (burntSomeone) time++;
    }

    return time;
}
