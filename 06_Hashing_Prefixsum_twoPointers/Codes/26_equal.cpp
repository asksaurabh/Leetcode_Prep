bool isLexicographicallySmaller(vector<int> temp, vector<int> res) {
    for (int i = 0; i < 4; i++) {
        if (temp[i] < res[i]) return true;
        if (res[i] < temp[i]) return false;
    }
    return false;
}

vector<int> Solution::equal(vector<int> &nums) {
    int n = nums.size();
    unordered_map<int, pair<int, int>> mp;
    vector<int> res = {n, n, n, n};

    for (int c = 0; c < n; c++) {
        for (int d = c + 1; d < n; d++) {

            int sum = nums[c] + nums[d];
            if (mp.find(sum) != mp.end()) {
                int a = mp[sum].first, b = mp[sum].second;
                if (a < c and b != c and b != d) {
                    vector<int> tempRes = {a, b, c, d};
                    if (isLexicographicallySmaller(tempRes, res)) res = tempRes;
                }
            }
            else {
                mp[sum] = {c, d};
            }
        }
    }

    if (res[0] == n) return {};
    return res;
}
