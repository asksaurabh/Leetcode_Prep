int Solution::diffPossible(const vector<int> &nums, int target) {

    unordered_map<int, int> mp;

    for (int i = 0; i < nums.size(); i++) {
        // For eg: 5, 2, 3 : t = 2
        // x - y = target
        // x = y + target, y = x - target
        // So standing at nums[i], it can be either x or y.

        int x = nums[i] + target;              // Considering y as nums[i]
        int y = nums[i] - target;              // Considering x as nums[i]

        if (mp.find(x) != mp.end() || mp.find(y) != mp.end()) return 1;

        mp[nums[i]] = i;
    }

    return 0;
}
