int Solution::removeDuplicates(vector<int> &nums) {

    int size = 1;
    for (int i = 1; i < nums.size(); i++) {
        if (nums[i] == nums[i - 1]) continue;
        else {
            nums[size] = nums[i];
            size++;
        }
    }

    return size;
}
