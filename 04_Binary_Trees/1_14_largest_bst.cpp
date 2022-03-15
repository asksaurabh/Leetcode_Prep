// Approach 1: Brute Force -> O(n * n)
// If its a valid bst -> count nodes
class Solution {
public:
	/*You are required to complete this method */
	// Return the size of the largest sub-tree which is also a BST

	int countNodes(Node* root) {
		if (root == nullptr) return 0;
		return 1 + countNodes(root->left) + countNodes(root->right);
	}

	bool isValid(Node* root, long long minValue, long long maxValue) {
		if (root == nullptr) return true;

		if (root->data >= maxValue || root->data <= minValue) return false;
		return isValid(root->left, minValue, root->data) && isValid(root->right, root->data, maxValue);
	}

	int largestBst(Node *root)
	{
		if (root == nullptr) return 0;

		if (isValid(root, LONG_MIN, LONG_MAX))
			return countNodes(root);

		return max(largestBst(root->left), largestBst(root->right));
	}
};

// Approach 2: Traversing in a post order fashion. T.C -> O(n)
class NodeValue {
public:
	int maxNode, minNode, maxSize;

	NodeValue(int minNode, int maxNode, int maxSize) {
		this->maxNode = maxNode;
		this->minNode = minNode;
		this->maxSize = maxSize;
	}
};

class Solution {
public:
	NodeValue getLargest(Node* root) {
		// An empty tree is a BST of size 0.
		if (root == nullptr) {
			return NodeValue(INT_MAX, INT_MIN, 0);
		}

		// Get values from left and right subtree of current tree.
		NodeValue left = getLargest(root->left);
		NodeValue right = getLargest(root->right);

		// Current node is greater than max in left AND smaller than min in right, it is a BST.
		if (root->data > left.maxNode and root->data < right.minNode) {
			return NodeValue(min(root->data, left.minNode), max(root->data, right.maxNode), left.maxSize + right.maxSize + 1);
		}

		// Otherwise, return [-inf, inf] so that parent can't be valid BST
		return NodeValue(INT_MIN, INT_MAX, max(left.maxSize, right.maxSize));
	}
	int largestBst(Node *root) {
		return getLargest(root).maxSize;
	}
};