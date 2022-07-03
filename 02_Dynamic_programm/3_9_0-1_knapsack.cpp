// Memo + rec

#define vvi vector<vector<int>>
#define vi vector<int>
int solve(int i, vi &weight, vi &value, int maxWeight, vvi &dp) {
  if (maxWeight == 0) return 0;
  if (i == 0) return 0;
  if (dp[i][maxWeight] != -1) return dp[i][maxWeight];

  if (weight[i - 1] > maxWeight) return dp[i][maxWeight] = solve(i - 1, weight, value, maxWeight, dp);
  return dp[i][maxWeight] = max(solve(i - 1, weight, value, maxWeight, dp),
                                value[i - 1] + solve(i - 1, weight, value, maxWeight - weight[i - 1], dp));
}

int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight)
{
  vvi dp(n + 1, vi (maxWeight + 1, -1));
  return solve(n, weight, value, maxWeight, dp);
}


// Tabulation
#define vvi vector<vector<int>>
#define vi vector<int>

int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight)
{
  vvi dp(n + 1, vi (maxWeight + 1, 0));
  for (int i = 0; i <= n; i++) dp[i][0] = 0;
  for (int j = 1; j <= maxWeight; j++) dp[0][j] = 0;

  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= maxWeight; j++) {
      if (weight[i - 1] > j) dp[i][j] = dp[i - 1][j];
      else dp[i][j] = max(dp[i - 1][j], value[i - 1] + dp[i - 1][j - weight[i - 1]]);
    }
  }

  return dp[n][maxWeight];
}

// Space Opt
#define vvi vector<vector<int>>
#define vi vector<int>

int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight)
{
  vector<int> prev(maxWeight + 1, 0), curr(maxWeight + 1, 0);
  prev[0] = 0, curr[0] = 0;
  for (int j = 1; j <= maxWeight; j++) prev[j] = 0;

  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= maxWeight; j++) {
      if (weight[i - 1] > j) curr[j] = prev[j];
      else curr[j] = max(prev[j], value[i - 1] + prev[j - weight[i - 1]]);
    }
    prev = curr;
  }

  return prev[maxWeight];
}