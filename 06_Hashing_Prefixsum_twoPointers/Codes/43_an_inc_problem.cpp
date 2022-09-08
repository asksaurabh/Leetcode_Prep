vector<int> Solution::solve(vector<int> &nums) {
    unordered_map<int, set<int>> mp;
    vector<int> res;

    for (int val : nums) res.push_back(val);

    for (int i = 0; i < nums.size(); i++) {
        if (mp.find(nums[i]) == mp.end()) mp[nums[i]].insert(i);
        else {
            auto first_occ = mp[nums[i]].begin();
            int first_index = *first_occ;

            mp[nums[i]].erase(first_occ);
            res[first_index] += 1;

            mp[res[first_index]].insert(first_index);
            mp[nums[i]].insert(i);
        }
    }

    return res;
}
