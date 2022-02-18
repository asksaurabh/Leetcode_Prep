// Memoized -> O(2^N), O(n * W) + O(n)
int getProfit(int index, int w, vector<int> &profit, vector<int> &weight, vector<vector<int>> &dp) {
    if (w == 0) return 0;
    if (index == 0) {
        int times = w / weight[0];
        return times * profit[0];
    }
    if (dp[index][w] != -1) return dp[index][w];

    if (weight[index] > w)
        return getProfit(index - 1, w, profit, weight, dp);

    return dp[index][w] = max(getProfit(index - 1, w, profit, weight, dp), profit[index] +
                              getProfit(index, w - weight[index], profit, weight, dp));
}

int unboundedKnapsack(int n, int w, vector<int> &profit, vector<int> &weight)
{
    vector<vector<int>> dp(n, vector<int> (w + 1, -1));
    return getProfit(n - 1, w, profit, weight, dp);
}

//Tabulation. -> O(n * W), O(n * W)
int unboundedKnapsack(int n, int w, vector<int> &profit, vector<int> &weight)
{
    vector<vector<int>> dp(n, vector<int> (w + 1, 0));          // Stores the max profit
    for (int i = 0; i < n; i++)
        dp[i][0] = 0;

    if (weight[0] <= w) {
        for (int j = weight[0]; j <= w; j++) {
            int times = j / weight[0];
            dp[0][j] = times * profit[0];
        }
    }

    for (int i = 1; i < n; i++) {
        for (int j = 1; j <= w; j++) {
            if (weight[i] > j) dp[i][j] = dp[i - 1][j];
            else dp[i][j] = max(dp[i - 1][j], profit[i] + dp[i][j - weight[i]]);
        }
    }

    return dp[n - 1][w];
}

// Space Optimized. -> T.C -> O(n * W) S.C -> O(w)
int unboundedKnapsack(int n, int w, vector<int> &profit, vector<int> &weight)
{
    vector<int> prevrow(w + 1, 0), curr(w + 1, 0);
    for (int i = 0; i < n; i++)
        prevrow[0] = 0;

    if (weight[0] <= w) {
        for (int j = weight[0]; j <= w; j++) {
            int times = j / weight[0];
            prevrow[j] = times * profit[0];
        }
    }

    for (int i = 1; i < n; i++) {
        for (int j = 1; j <= w; j++) {
            if (weight[i] > j) curr[j] = prevrow[j];
            else curr[j] = max(prevrow[j], profit[i] + curr[j - weight[i]]);
        }
        prevrow = curr;
    }

    return prevrow[w];
}
