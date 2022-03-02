// Approach: T.C -> O(n)

#include<climits>
int minSubarraySum(int arr[], int n, int k)
{
    int i = 0, j = 0, currsum = 0, minsum = INT_MAX;

    while (j < n) {
        currsum += arr[j];

        if (j - i + 1 < k) {
            j++;
        }

        else if (j - i + 1 == k) {
            minsum = min(minsum, currsum);
            currsum -= arr[i];
            i++, j++;
        }
    }

    return minsum;
}