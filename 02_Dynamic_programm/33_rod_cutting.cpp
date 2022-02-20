// Created a array of len of rod
int maxProfit(int index, int rodLength, vector<int> &len, vector<int> &price, vector<vector<int>> &dp) {
    if (rodLength == 0) return 0;
    if (index == 0) {
        int times = rodLength / len[0];
        return price[0] * times;
    }
    if (dp[index][rodLength] != -1) return dp[index][rodLength];

    if (len[index] > rodLength)
        return maxProfit(index - 1, rodLength, len, price, dp);

    return dp[index][rodLength] = max(maxProfit(index - 1, rodLength, len, price, dp), price[index] +
                                      maxProfit(index, rodLength - len[index], len, price, dp));
}
int cutRod(vector<int> &price, int n)
{
    vector<int> len(n, 0);
    for (int i = 0; i < n; i++)
        len[i] = i + 1;

    vector<vector<int>> dp(n, vector<int> (n + 1, -1));
    return maxProfit(n - 1, n, len, price, dp);
}

// Approach 2:
// Without creating a len of rods. (Means calculating the current rod length on fly.(index + 1))
// Memoized. T.C -> O(2^n)

int maxProfit(int index, int totalLength, vector<int> &price, vector<vector<int>> &dp) {
    if (totalLength == 0) return 0;
    if (index == 0) {
        // Means current rod length = 1
        return totalLength * price[0];
    }
    if (dp[index][totalLength] != -1) return dp[index][totalLength];

    int currRodLength = index + 1;
    if (currRodLength > totalLength)
        return maxProfit(index - 1, totalLength, price, dp);

    return dp[index][totalLength] = max(maxProfit(index - 1, totalLength, price, dp), price[index] +
                                        maxProfit(index, totalLength - currRodLength, price, dp));
}
int cutRod(vector<int> &price, int n)
{
    vector<vector<int>> dp(n, vector<int> (n + 1, -1));
    return maxProfit(n - 1, n, price, dp);
}

// Approach 3: Tabulation
int cutRod(vector<int> &price, int n)
{
    vector<vector<int>> dp(n, vector<int> (n + 1, 0));
    for (int i = 0; i < n; i++)
        dp[i][0] = 0;

    for (int j = 1; j <= n; j++)
        dp[0][j] = j * price[0];

    for (int i = 1; i < n; i++) {
        for (int j = 1; j <= n; j++) {
            int currLength = i + 1;
            if (currLength > j) dp[i][j] = dp[i - 1][j];
            else dp[i][j] = max(dp[i - 1][j], price[i] + dp[i][j - currLength]);
        }
    }

    return dp[n - 1][n];
}

// Space Optimized
int cutRod(vector<int> &price, int n)
{
    vector<int> prev(n + 1, 0), curr(n + 1, 0);
    for (int i = 0; i < n; i++)
        prev[0] = 0;

    for (int j = 1; j <= n; j++)
        prev[j] = j * price[0];

    for (int i = 1; i < n; i++) {
        for (int j = 1; j <= n; j++) {
            int currLength = i + 1;
            if (currLength > j) curr[j] = prev[j];
            else curr[j] = max(prev[j], price[i] + curr[j - currLength]);
        }
        prev = curr;
    }

    return prev[n];
}
