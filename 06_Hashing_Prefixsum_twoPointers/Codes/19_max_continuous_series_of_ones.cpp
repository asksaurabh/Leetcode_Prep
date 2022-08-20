vector<int> Solution::maxone(vector<int> &nums, int flips) {
    int i = 0, j = 0, maxLength = 0;
    vector<int> res;
    int st = 0, end = 0;
    int countZeroes = 0;

    while (j < nums.size()) {
        if (nums[j] == 0) countZeroes++;

        while (countZeroes > flips) {
            if (nums[i] == 0) countZeroes--;
            i++;
        }

        if (j - i + 1 > maxLength) {
            st = i, end = j, maxLength = j - i + 1;
        }

        j++;
    }

    if (st == 0 and end == 0 and nums[0] == 0) return res;
    for (int i = st; i <= end; i++) res.push_back(i);

    return res;
}
