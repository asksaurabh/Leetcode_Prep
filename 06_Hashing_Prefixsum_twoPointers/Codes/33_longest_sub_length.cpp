int Solution::solve(vector<int> &nums) {

    // If I replace 0 with -1, then I need to find
    // the longest subarray with sum(k) = 1.

    int maxLength = 0;
    int n = nums.size();
    int currSum = 0, k = 1;
    unordered_map<int, int> mp;

    for (int i = 0; i < n; i++) {
        currSum += (nums[i] == 0 ? -1 : 1);

        if (currSum == k) maxLength = i + 1;
        else if (mp.find(currSum - k) != mp.end())
            maxLength = max(maxLength, i - mp[currSum - k]);
        if (mp.find(currSum) == mp.end()) mp[currSum] = i;
    }

    return maxLength;
}
