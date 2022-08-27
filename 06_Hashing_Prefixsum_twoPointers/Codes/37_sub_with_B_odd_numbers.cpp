int Solution::solve(vector<int> &nums, int B) {

    // Odd no have last bit set.
    // B set bits will sum to 1
    // Ques changes to -> Find total subarrays with sum B.

    unordered_map<int, int> mp;
    int sum = 0;
    int n = nums.size();
    int totalSubarrays = 0;

    for (int i = 0; i < n; i++) {
        sum += (nums[i] & 1);

        if (sum == B) totalSubarrays += 1;
        if (mp.find(sum - B) != mp.end()) totalSubarrays += mp[sum - B];
        mp[sum]++;
    }

    return totalSubarrays;
}
