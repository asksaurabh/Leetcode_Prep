vector<int> Solution::lszero(vector<int> &nums) {

    int n = nums.size();
    unordered_map<int, int> mp;
    int maxLength = 0, currSum = 0, start = 0;

    for (int i = 0; i < n; i++) {
        currSum += nums[i];
        int key = currSum - 0;

        if (currSum == 0) {
            maxLength = i + 1;
            start = 0;
        }

        else if (mp.find(key) != mp.end()) {
            if (i - mp[key] > maxLength) {
                maxLength = i - mp[key];
                start = mp[key] + 1;
            }
        }

        if (mp.find(currSum) == mp.end()) {
            mp[currSum] = i;
        }
    }

    vector<int> res;
    for (int i = start; i < start + maxLength; i++) {
        res.push_back(nums[i]);
    }

    return res;
}
