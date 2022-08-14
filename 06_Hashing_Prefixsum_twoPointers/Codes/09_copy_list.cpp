// Approach 1: T.C -> O(n), S.C -> O(n)
#define ListNode RandomListNode
RandomListNode* Solution::copyRandomList(RandomListNode* head) {
	unordered_map<ListNode*, ListNode*> copy;

	ListNode* temp = head;
	while (temp) {
		copy[temp] = new ListNode(temp->label);
		temp = temp->next;
	}

	temp = head;

	while (temp) {
		if (temp->next) copy[temp]->next = copy[temp->next];
		if (temp->random) copy[temp]->random = copy[temp->random];
		temp = temp->next;
	}

	return copy[head];
}

// Approach 2: T.C -> O(n), S.C -> O(1)
#define ListNode RandomListNode
RandomListNode* Solution::copyRandomList(RandomListNode* head) {
	if (head == nullptr) return nullptr;

	//Step1: Insert deep copy of each node right after it.
	ListNode* temp = head;
	while (temp) {
		ListNode* next = temp->next;
		temp->next = new ListNode(temp->label);
		temp->next->next = next;
		temp = temp->next->next;
	}

	// Step2: Assign random pointers to copy nodes
	temp = head;
	while (temp) {
		ListNode* copyNode = temp->next;
		if (temp->random) copyNode->random = temp->random->next;
		temp = temp->next->next;
	}

	// Step3: Separate the original and deep copy LL
	temp = head;
	ListNode* copyListHead = temp->next;
	ListNode* copyListIterator = temp->next;

	while (temp) {
		temp->next = copyListIterator->next;
		temp = temp->next;
		if (temp) {
			copyListIterator->next = temp->next;
		}
		copyListIterator = copyListIterator->next;
	}

	return copyListHead;
}