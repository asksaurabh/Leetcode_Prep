// Approach 1: Two trav
int Solution::solve(vector<int> &nums) {
    int n = nums.size();
    unordered_map<int, int> mp;

    for (int i = 0; i < n; i++) {
        mp[nums[i]]++;
    }

    for (int i = 0; i < n; i++) {
        if (mp[nums[i]] > 1) return nums[i];
    }

    return -1;
}

// Approach 2: One trav
int Solution::solve(vector<int> &nums) {

    // num -> {freq, first_occ}
    unordered_map<int, int> freq, firstOcc;
    int n = nums.size();
    int result_index = n;

    for (int i = 0; i < n; i++) {
        freq[nums[i]]++;
        if (firstOcc.find(nums[i]) == firstOcc.end()) firstOcc[nums[i]] = i;
        if (freq[nums[i]] > 1) result_index = min(result_index, firstOcc[nums[i]]);
    }

    return result_index == n ? -1 : nums[result_index];
}
