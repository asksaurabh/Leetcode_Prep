// Memoization
int solve(int i, vi &weight, vi &value, int maxWeight, vvi &dp) {
    if (maxWeight == 0) return 0;
    if (i == 0) {
        if (weight[0] <= maxWeight) return value[0];
        else return 0;
    }
    if (dp[i][maxWeight] != -1) return dp[i][maxWeight];

    if (weight[i] > maxWeight) {
        return dp[i][maxWeight] = solve(i - 1, weight, value, maxWeight, dp);
    }

    return dp[i][maxWeight] = max(value[i] + solve(i - 1, weight, value, maxWeight - weight[i], dp),                                             solve(i - 1, weight, value, maxWeight, dp));
}


// Tabulation
int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight)
{
    vvi dp(n, vi(maxWeight + 1, 0));
//     return solve(n-1, weight, value, maxWeight, dp);

    for (int i = 0; i < n; i++) dp[i][0] = 0;
    for (int j = weight[0]; j <= maxWeight; j++) {
        dp[0][j] = value[0];
    }

    for (int i = 1; i < n; i++) {
        for (int j = 1; j <= maxWeight; j++) {
            if (weight[i] > j) dp[i][j] = dp[i - 1][j];
            else dp[i][j] = max(value[i] + dp[i - 1][j - weight[i]], dp[i - 1][j]);
        }
    }

    return dp[n - 1][maxWeight];
}

// Space Opt:
// int tabulate(vector<int> &weight, vector<int> &value, int n, int W) {
// //     vector<vector<int>> dp(n, vector<int> (W + 1, 0));
//     vector<int> prevrow(W + 1, 0), curr(W + 1, 0);

//     for(int j = weight[0]; j <= W; j++)
//         prevrow[j] = value[0];

//     for(int i = 1; i < n; i++) {
//         for(int j = 0; j <= W; j++) {
//             if(weight[i] > j)
//                 curr[j] = prevrow[j];
//             else
//                 curr[j] = max(prevrow[j], value[i] + prevrow[j - weight[i]]);
//         }
//         prevrow = curr;
//     }

//     return prevrow[W];
// }

// MOREMORE OPTIMIZED
int tabulate(vector<int> &weight, vector<int> &value, int n, int W) {
//     vector<vector<int>> dp(n, vector<int> (W + 1, 0));
    vector<int> prevrow(W + 1, 0);

    for (int j = weight[0]; j <= W; j++)
        prevrow[j] = value[0];

    for (int i = 1; i < n; i++) {
        for (int j = W; j >= 0; j--) {
            if (weight[i] > j)
                prevrow[j] = prevrow[j];
            else
                prevrow[j] = max(prevrow[j], value[i] + prevrow[j - weight[i]]);
        }
    }

    return prevrow[W];
}

int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight)
{
//  vector<vector<int>> dp(n, vector<int> (maxWeight + 1, -1));
//     return maxValue(n - 1, weight, value, maxWeight, dp);

    return tabulate(weight, value, n, maxWeight);
}