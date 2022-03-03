// T.C -> O(N * N * M)
// S.C -> O(N * M)

// Explaination: As we are merging 2 lists at a time,

// After adding first 2 lists, time taken will be O(M+M) = O(2M).
// Then we will merge another list to above merged list -> time = O(2M + M) = O(3M).
// Then we will merge another list -> time = O(3M + M).
// We will keep merging lists to previously merged lists until all lists are merged.
// Total time taken will be O(2M + 3M + 4M + …. N*M) = (2 + 3 + 4 + … + N)*M
// Using arithmatic sum formula: time = O((N*N + N – 2)*M/2)
// Above expression is roughly equal to O(N*N*M) for large value of N

Node* merge(Node *l1, Node *l2) {
    if (l1 == NULL) return l2;
    if (l2 == NULL) return l1;

    Node* newHead = NULL;
    if (l1->data <= l2->data) {
        newHead = l1;
        newHead->bottom = merge(l1->bottom, l2);
    }
    else {
        newHead = l2;
        newHead->bottom = merge(l1, l2->bottom);
    }

    return newHead;
}

Node *flatten(Node *root)
{
    if (root == NULL || root->next == NULL) return root;

    // recur to the list on right. (Ask for right to merge them)
    root->next = flatten(root->next);

    // Do the current merge.
    root = merge(root, root->next);

    return root;
}