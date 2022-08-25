int Solution::solve(vector<int> &nums, int k) {
    int count = 0;
    int i = 0, j = 0;
    int currSum = 0, n = nums.size();

    while (j < n) {
        currSum += nums[j];

        while (currSum >= k) {
            currSum -= nums[i];
            i++;
        }

        count += (j - i + 1);
        j++;
    }

    return count;
}
