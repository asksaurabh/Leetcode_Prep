// Approach 1: Brute force. T.C -> O(n) + O(logn), S.C -> O(n)
void inorderTraversal(binaryTreeNode *root, vector<int> &inorder) {
	if (root == nullptr) return;

	inorderTraversal(root->left, inorder);
	inorder.push_back(root->data);
	inorderTraversal(root->right, inorder);
}
int binarySearch(vector<int> &arr, int key) {
	int low = 0, high = arr.size() - 1;
	while (low <= high) {
		int mid = low + (high - low) / 2;
		if (arr[mid] == key) return mid;
		else if (arr[mid] > key) high = mid - 1;
		else low = mid + 1;
	}
	return -1;
}
vector<int> findPreSuc(binaryTreeNode *root, int key) {
	vector<int> inorder;
	inorderTraversal(root, inorder);

	// Inorder of bst is sorted.
	// Find key in sorted array
	int pos = binarySearch(inorder, key);
	int n = inorder.size();
	vector<int> res;

	if (pos == -1 || n == 1) {
		res.push_back(-1);
		res.push_back(-1);
	}
	else if (pos > 0 and pos < n - 1) {
		res.push_back(inorder[pos - 1]);
		res.push_back(inorder[pos + 1]);
	}
	else if (pos == 0) {
		res.push_back(-1);
		res.push_back(inorder[pos + 1]);
	} else if (pos == n - 1) {
		res.push_back(inorder[pos - 1]);
		res.push_back(-1);
	}

	return res;
}

// Approach 2: T.C -> O(N), S.C -> O(1) using morris traversal

vector<int> findPreSuc(binaryTreeNode *root, int key) {
	// Perform inorder supposing its a BT.
	// First value that u encounter which is greater than key -> successor
	// First value that u encounter which is smaller than key -> predecessor
}

// Approach 3: Use the fact that its a BST. Try to get closer on the key.
// T.C -> O(h), S.C -> O(1)

// returns a value just greater than key, assuming key is present
int inorderSuccessor(binaryTreeNode* root, int key) {
	int successor = -1;
	while (root) {
		if (root->data <= key) {
			root = root->right;
		} else if (root->data > key) {
			successor = root->data;
			// Try to get closer to key
			root = root->left;
		}
	}
	return successor;
}

// returns a value just smaller than key, assuming key is present
int inorderPredecessor(binaryTreeNode* root, int key) {
	int predecessor = -1;
	while (root) {
		if (root->data >= key) {
			root = root->left;
		} else if (root->data < key) {
			predecessor = root->data;
			// Try to get closer to key
			root = root->right;
		}
	}
	return predecessor;
}

vector<int> findPreSuc(binaryTreeNode *root, int key)
{
	vector<int> res;
	int successor = inorderSuccessor(root, key);
	int predecessor = inorderPredecessor(root, key);

	res.push_back(predecessor);
	res.push_back(successor);

	return res;
}