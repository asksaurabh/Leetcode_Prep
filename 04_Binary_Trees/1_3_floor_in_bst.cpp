// Approach 1: Iterative
int floorInBST(TreeNode<int> * root, int key) {
	int floor = -1;
	while (root) {
		if (root->val == key) return root->val;
		else if (root->val < key) {
			// possible answer
			floor = root->val;
			root = root->right;
		} else {
			root = root->left;
		}
	}

	return floor;
}

// Approach 2:
void getFloor(TreeNode<int> * root, int key, int &floor) {
	if (root == nullptr) return;

	if (root->val == key) {
		floor = root->val;
		return;
	}
	else if (root->val < key) {
		// Possible answer
		floor = root->val;
		getFloor(root->right, key, floor);
	}
	else {
		getFloor(root->left, key, floor);
	}
}
int floorInBST(TreeNode<int> * root, int key) {
	int floor = -1;
	getFloor(root, key, floor);
	return floor;
}