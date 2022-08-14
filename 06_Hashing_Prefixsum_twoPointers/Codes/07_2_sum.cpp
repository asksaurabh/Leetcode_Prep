// T.C -> O(n)
vector<int> Solution::twoSum(const vector<int> &nums, int target) {
    unordered_map<int, int> mp;

    for (int i = 0; i < nums.size(); i++) {

        if (mp.find(target - nums[i]) != mp.end()) {
            vector<int> res;
            res.push_back(mp[target - nums[i]]);
            res.push_back(i + 1);
            return res;
        }

        // Only store the minimum occ index of a number.
        else if (mp.find(nums[i]) == mp.end())
            mp[nums[i]] = i + 1;
    }

    return {};
}
