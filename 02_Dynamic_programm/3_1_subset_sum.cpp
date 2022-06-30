// Approach: Using Indicies
// Approach 1: Space Opt.
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


// Approach 2: Tabulation
bool subsetSumToK(int n, int k, vector<int> &arr) {
    vector<vector<bool>> dp(n, vector<bool> (k + 1, false));

    for (int i = 0; i < n; i++)
        dp[i][0] = true;

    dp[0][arr[0]] = true;

    for (int i = 1; i < n; i++) {
        for (int sum = 1; sum <= k; sum++) {
            if (arr[i] > sum) dp[i][sum] = dp[i - 1][sum];
            else dp[i][sum] = dp[i - 1][sum] || dp[i - 1][sum - arr[i]];
        }
    }

    return dp[n - 1][k];
}


// Previous Approaches: Using size as parameter
// Top-Down
bool solve(int i, int k, vector<int> &arr, vector<vector<int>> &dp) {
    if (k == 0) return true;
    if (i == 0) return false;
    if (dp[i][k] != -1) return dp[i][k];
    if (arr[i - 1] > k) return solve(i - 1, k, arr, dp);

    return dp[i][k] = solve(i - 1, k - arr[i - 1], arr, dp) || solve(i - 1, k, arr, dp);
}
bool subsetSumToK(int n, int k, vector<int> &arr) {
    vector<vector<int>> dp(n + 1, vector<int> (k + 1, -1));
    return solve(n, k, arr, dp);
}


// Bottom-Up
bool subsetSumToK(int n, int k, vector<int> &arr) {
    vector<vector<int>> dp(n + 1, vector<int> (k + 1, 0));
    for (int i = 0; i <= n; i++) dp[i][0] = 1;
    for (int j = 1; j <= k; j++) dp[0][j] = 0;

    for (int i = 1; i <= n; i++) {
        for (int sum = 1; sum <= k; sum++) {
            if (arr[i - 1] > sum) dp[i][sum] = dp[i - 1][sum];
            else dp[i][sum] = (dp[i - 1][sum - arr[i - 1]] || dp[i - 1][sum]);
        }
    }

    return dp[n][k];
}


// Space Opt:
bool subsetSumToK(int n, int k, vector<int> &arr) {
    vector<vector<int>> dp(n + 1, vector<int> (k + 1, 0));
    vector<int> prev(k + 1, 0), curr(k + 1, 0);

//     for(int i = 0; i <= n; i++) dp[i][0] = 1;
    prev[0] = 1;
    curr[0] = 1;

//     for(int j = 1; j <= k; j++) dp[0][j] = 0;

    for (int i = 1; i <= n; i++) {
        for (int sum = 1; sum <= k; sum++) {
            if (arr[i - 1] > sum) curr[sum] = prev[sum];
            else curr[sum] = (prev[sum - arr[i - 1]] || prev[sum]);
        }
        prev = curr;
    }

    return prev[k];
}