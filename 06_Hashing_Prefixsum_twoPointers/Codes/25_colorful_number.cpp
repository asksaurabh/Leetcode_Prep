int Solution::colorful(int N) {

    vector<int> nums;
    while (N > 0) {
        nums.push_back(N % 10);
        N /= 10;
    }

    int n = nums.size();
    unordered_set<int> st;

    // n = log10N (Number of digits of N)
    // T.C -> O(n^2 * log(n))

    for (int i = 0; i < n; i++) {
        int currProduct = 1;
        for (int j = i; j < n; j++) {
            currProduct *= nums[j];
            if (st.count(currProduct)) return 0;
            st.insert(currProduct);
        }
    }

    return 1;
}
