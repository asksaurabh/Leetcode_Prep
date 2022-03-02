//Approach T.C -> O(n^2)
class Solution {
public:
    int maximumSumSubarray(int K, vector<int> &arr , int N) {

        int maxsum = INT_MIN;

        // Find sum of all subarrays of size k
        for (int i = 0; i <= N - K; i++) {
            int currsum = 0;

            for (int j = 0; j < K; j++) {
                currsum += arr[i + j];
            }

            maxsum = max(maxsum, currsum);
        }

        return maxsum;
    }
};


// Approach T.C -> O(n).
class Solution {
public:
    int maximumSumSubarray(int K, vector<int> &arr , int N) {

        int i = 0, j = 0, currsum = 0, maxsum = INT_MIN;
        while (j < N) {
            currsum += arr[j];

            if (j - i + 1 < K)
                j++;

            else if (j - i + 1 == K) {
                maxsum = max(maxsum, currsum);
                currsum -= arr[i];
                i++, j++;
            }
        }

        return maxsum;
    }
};