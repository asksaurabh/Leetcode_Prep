int Solution::solve(vector<int> &nums, int B, int C) {

    // Change this question to subarray with sum zero
    int n = nums.size();
    int currSum = 0;
    unordered_map<int, int> mp;
    int count = 0;

    for (int i = 0; i < n; i++) {
        if (nums[i] == B) currSum += 1;
        else if (nums[i] == C) currSum -= 1;

        if (currSum == 0) count += 1;
        if (mp.find(currSum - 0) != mp.end()) count += mp[currSum - 0];

        mp[currSum]++;
    }

    return count;
}
