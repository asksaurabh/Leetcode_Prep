// int maxValue(int index, vector<int> &weight, vector<int> &value, int W, vector<vector<int>> &dp) {
//     if (index == 0) {
//         if (weight[0] <= W) return value[0];
//         return 0;
//     }
//     if (dp[index][W] != -1) return dp[index][W];

//     if (weight[index] > W)
//         return maxValue(index - 1, weight, value, W, dp);

//     return dp[index][W] = max(maxValue(index - 1, weight, value, W, dp), value[index] +
//                               maxValue(index - 1, weight, value, W - weight[index], dp));
// }

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