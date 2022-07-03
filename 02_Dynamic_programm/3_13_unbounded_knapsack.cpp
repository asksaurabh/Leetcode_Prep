// Rec + Memo
int solve(int i, int maxWeight, vector<int> &profit, vector<int> &weight, vector<vector<int>> &dp) {
	if (maxWeight == 0) return 0;
	if (i == 0) return 0;
	if (dp[i][maxWeight] != -1) return dp[i][maxWeight];

	if (weight[i - 1] > maxWeight) return dp[i][maxWeight] = solve(i - 1, maxWeight, profit, weight, dp);

	return dp[i][maxWeight] = max(solve(i - 1, maxWeight, profit, weight, dp),
	                              profit[i - 1] + solve(i, maxWeight - weight[i - 1], profit, weight, dp));

}
int unboundedKnapsack(int n, int w, vector<int> &profit, vector<int> &weight)
{
	vector<vector<int>> dp(n + 1, vector<int> (w + 1, -1));
	return solve(n, w, profit, weight, dp);
}


// Tabulation
int unboundedKnapsack(int n, int w, vector<int> &profit, vector<int> &weight)
{
	vector<vector<int>> dp(n + 1, vector<int> (w + 1, 0));

	for (int i = 0; i <= n; i++) dp[i][0] = 0;
	for (int j = 1; j <= w; j++) dp[0][j] = 0;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= w; j++) {
			if (weight[i - 1] > j) dp[i][j] = dp[i - 1][j];
			else dp[i][j] = max(dp[i - 1][j], profit[i - 1] + dp[i][j - weight[i - 1]]);
		}
	}

	return dp[n][w];
}


// Space Opt:

int unboundedKnapsack(int n, int w, vector<int> &profit, vector<int> &weight)
{
	vector<int> prev(w + 1, 0), curr(w + 1, 0);

	prev[0] = 0, curr[0] = 0;
	for (int j = 1; j <= w; j++) prev[j] = 0;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= w; j++) {
			if (weight[i - 1] > j) curr[j] = prev[j];
			else curr[j] = max(prev[j], profit[i - 1] + curr[j - weight[i - 1]]);
		}
		prev = curr;
	}

	return prev[w];
}
