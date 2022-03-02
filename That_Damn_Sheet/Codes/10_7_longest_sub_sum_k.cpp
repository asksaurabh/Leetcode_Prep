// Approach: T.C -> O(n)

class Solution {
public:
    int lenOfLongSubarr(int arr[],  int n, int k)
    {
        int maxLength = 0;
        int prefix_sum = 0;
        unordered_map<int, int> mp;

        for (int i = 0; i < n; i++) {
            prefix_sum += arr[i];

            if (prefix_sum == k)
                maxLength = i + 1;

            if (mp.find(prefix_sum) == mp.end()) {
                mp[prefix_sum] = i;
            }

            if (mp.find(prefix_sum - k) != mp.end()) {
                maxLength = max(maxLength, i - mp[prefix_sum - k]);
            }
        }

        return maxLength;
    }

};