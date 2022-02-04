Approach 1: T.C -> O(2 ^ n)
class Solution
{
public:
    void getSubsetSums(vector<int> &arr, int lastIndex, vector<int> &res, int curr_sum) {

        if (lastIndex < 0) {
            res.push_back(curr_sum);
            return;
        }

        getSubsetSums(arr, lastIndex - 1, res, curr_sum);
        getSubsetSums(arr, lastIndex - 1, res, curr_sum + arr[lastIndex]);
    }

    vector<int> subsetSums(vector<int> arr, int N)
    {
        vector<int> res;

        sort(arr.begin(), arr.end());             // As u have to return in ing order
        getSubsetSums(arr, N - 1, res, 0);

        return res;
    }
};