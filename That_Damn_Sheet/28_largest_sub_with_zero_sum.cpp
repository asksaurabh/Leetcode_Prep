// Approach 1: T.C -> O(n^2)
class Solution {
public:
    int maxLen(vector<int> &arr, int n) {

        int maxL = 0;

        for (int i = 0; i < n; i++) {
            int curr_sum = 0;
            for (int j = i; j < n; j++) {
                curr_sum += arr[j];
                if (curr_sum == 0)
                    maxL = max(maxL, j - i + 1);
            }
        }

        return maxL;
    }
};


// Approach 2: T.C -> O(n), S.C -> O(n)
class Solution {
public:
    int maxLen(vector<int> &arr, int n) {

        int prefix_sum = 0;
        int maxL = 0;
        unordered_map<int, int> mp;     // <prefix_sum, index>

        for (int i = 0; i < n; i++) {
            prefix_sum += arr[i];

            if (prefix_sum == 0) {
                maxL = max(maxL, i + 1);
            }

            else {
                if (mp.find(prefix_sum) != mp.end())
                    maxL = max(maxL, i - mp[prefix_sum]);
                else
                    mp[prefix_sum] = i;
            }
        }

        return maxL;
    }
};