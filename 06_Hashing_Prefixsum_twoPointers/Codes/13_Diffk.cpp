int bs(vector<int> &nums, int start, int end, int key) {
    while (start <= end) {
        int mid = start + (end - start) / 2;
        if (nums[mid] == key) return true;
        else if (nums[mid] > key) end = mid - 1;
        else start = mid + 1;
    }

    return false;
}
int Solution::diffPossible(vector<int> &nums, int k) {

    for (int j = 0; j < nums.size(); j++) {
        int numsi = k + nums[j];
        if (bs(nums, j + 1, nums.size() - 1, numsi)) return true;
    }

    return false;
}
