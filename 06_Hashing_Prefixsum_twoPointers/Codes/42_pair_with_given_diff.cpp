int Solution::solve(vector<int> &nums, int B) {
    int n = nums.size();
    unordered_set<int> st;

    for (int i = 0; i < n; i++) {
        // x - y = B
        // x = nums[i] + B, y = nums[i] - B

        int key1 = nums[i] + B;
        int key2 = nums[i] - B;

        if (st.find(key1) != st.end() || st.find(key2) != st.end()) return 1;
        st.insert(nums[i]);
    }

    return 0;
}
