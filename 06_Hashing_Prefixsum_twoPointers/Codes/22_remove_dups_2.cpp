int Solution::removeDuplicates(vector<int> &nums) {

    int i = 0, j = 1;
    bool isPrevDup = false;
    int n = nums.size();

    while (j < n) {
        if (nums[i] != nums[j]) {
            i++;
            nums[i] = nums[j];
            isPrevDup = false;
        }
        else {
            if (isPrevDup == false) {
                isPrevDup = true;
                i++;
                nums[i] = nums[j];
            }
        }

        j++;
    }

    return i + 1;
}
