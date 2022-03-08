// Approach: T.C -> O(n * m), S.C -> O(n * m)
int longestRepeatingSubsequence(string x, int n)
{
	// Find lcs of x with itself
	// Make sure that when u find a match they aren't at the same position
	vector<vector<int>> dp(n + 1, vector<int> (n + 1, 0));
	string y = x;

	for (int i = 0; i <= n; i++) {
		dp[i][0] = 0;
		dp[0][i] = 0;
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {

			if (x[i - 1] == y[j - 1] and i - 1 != j - 1) dp[i][j] = 1 + dp[i - 1][j - 1];
			else dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);

		}
	}

	return dp[n][n];
}

// Approach: S.C -> O(n)
int longestRepeatingSubsequence(string x, int n)
{
	// Find lcs of x with itself
	// Make sure that when u find a match they aren't at the same position
	vector<int> prev(n + 1, 0), curr(n + 1, 0);
	string y = x;

	for (int i = 0; i <= n; i++) {
		prev[i] = 0;
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {

			if (x[i - 1] == y[j - 1] and i - 1 != j - 1) curr[j] = 1 + prev[j - 1];
			else curr[j] = max(curr[j - 1], prev[j]);

		}
		prev = curr;
	}

	return prev[n];
}
