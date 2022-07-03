// Memo + Rec
int solve(int lengthToCutFromAvailable, int lengthAvailableToCut, vector<int> &price, vector<vector<int>> &dp) {
	int i = lengthToCutFromAvailable, j = lengthAvailableToCut;
	if (j == 0) return 0;
	if (i == 0) return 0;
	if (dp[i][j] != -1) return dp[i][j];

	if (lengthToCutFromAvailable > lengthAvailableToCut) {
		return dp[i][j] = solve(i - 1, j, price, dp);
	}

	return dp[i][j] = max(solve(i - 1, j, price, dp), price[i - 1] + solve(i, j - i, price, dp));
}
int cutRod(vector<int> &price, int n)
{
	vector<vector<int>> dp(n + 1, vector<int> (n + 1, -1));
	return solve(n, n, price, dp);
}

// tabulation
int cutRod(vector<int> &price, int n)
{
	vector<vector<int>> dp(n + 1, vector<int> (n + 1, 0));
	// max cost
	for (int i = 0; i <= n; i++) dp[i][0] = 0;
	for (int j = 1; j <= n; j++) dp[0][j] = 0;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (i > j) dp[i][j] = dp[i - 1][j];
			else dp[i][j] = max(dp[i - 1][j], price[i - 1] + dp[i][j - i]);
		}
	}

	return dp[n][n];
}

// Space Opt:
int cutRod(vector<int> &price, int n)
{
	vector<vector<int>> dp(n + 1, vector<int> (n + 1, 0));
	vector<int> prev(n + 1, 0), curr(n + 1, 0);
	// max cost
	prev[0] = 0, curr[0] = 0;
	for (int j = 1; j <= n; j++) prev[j] = 0;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (i > j) curr[j] = prev[j];
			else curr[j] = max(prev[j], price[i - 1] + curr[j - i]);
		}
		prev = curr;
	}

	return prev[n];
}


// easier to think
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