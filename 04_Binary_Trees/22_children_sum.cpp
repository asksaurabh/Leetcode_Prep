// Approach:
#define Node BinaryTreeNode
#include<bits/stdc++.h>
void changeTree(BinaryTreeNode < int > * root) {
    if (root == nullptr) return;
    if (root->left == nullptr and root->right == nullptr) return;

    int childrenSum = 0;
    if (root->left) childrenSum += root->left->data;
    if (root->right) childrenSum += root->right->data;

    int diff = root->data - childrenSum;
    if (diff > 0) {
        if (root->left) root->left->data += diff;
        else root->right->data += diff;
    }

    changeTree(root->left);
    changeTree(root->right);

    root->data = (root->left ? root->left->data : 0) + (root->right ? root->right->data : 0);
}


// Approach:
// T.C -> O(n), S.C -> O(h)
void changeTree(BinaryTreeNode < int > * root) {
    if (root == nullptr) return;

    int childrenSum = 0;
    if (root->left) childrenSum += root->left->data;
    if (root->right) childrenSum += root->right->data;

    if (childrenSum >= root->data) root->data = childrenSum;
    else {
        // Assign those children max values
        if (root->left) root->left->data = root->data;
        if (root->right) root->right->data = root->data;
    }

    // Move to the left and right do the same thing to them also
    changeTree(root->left);
    changeTree(root->right);

    // Now, after u have come back, normalize finally.(BackTrack)
    childrenSum = 0;
    if (root->left) childrenSum += root->left->data;
    if (root->right) childrenSum += root->right->data;
    // Assign that to the root
    if (root->left || root->right) root->data = childrenSum;
}