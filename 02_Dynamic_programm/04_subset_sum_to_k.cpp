bool subsetSumToK(int n, int k, vector<int> &arr) {
    vector<vector<bool>> dp(n, vector<bool> (k + 1, false));

    vector<bool> prev(k + 1, 0);
    vector<bool> curr(k + 1, 0);

    prev[0] = true;             // U can achieve sum = 0 by selecting no one
    curr[0] = true;
//     for(int i = 0; i < n; i++)
//         dp[i][0] = true;

//     dp[0][arr[0]] = true;
    prev[arr[0]] = true;

    for (int i = 1; i < n; i++) {
        for (int sum = 1; sum <= k; sum++) {
            if (arr[i] > sum) curr[sum] = prev[sum];
            else curr[sum] = prev[sum] || prev[sum - arr[i]];
        }
        prev = curr;
    }

    return prev[k];
}

// bool subsetSumToK(int n, int k, vector<int> &arr) {
//     vector<vector<bool>> dp(n, vector<bool> (k + 1, false));

//     for(int i = 0; i < n; i++)
//         dp[i][0] = true;

//     dp[0][arr[0]] = true;

//     for(int i = 1; i < n; i++) {
//         for(int sum = 1; sum <= k; sum++) {
//             if(arr[i] > sum) dp[i][sum] = dp[i-1][sum];
//             else dp[i][sum] = dp[i-1][sum] || dp[i-1][sum - arr[i]];
//         }
//     }

//     return dp[n-1][k];
// }