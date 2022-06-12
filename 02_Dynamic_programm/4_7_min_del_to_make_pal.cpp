// Approach 1:
// Min del = n - lps
int minDeletions(string str, int n) {
	string rev = str;
	reverse(rev.begin(), rev.end());
	int dp[n + 1][n + 1];
	memset(dp, 0, sizeof(dp));

	for (int i = 0; i <= n; i++) dp[0][i] = 0;
	for (int i = 0; i <= n; i++) dp[i][0] = 0;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (str[i - 1] == rev[j - 1]) dp[i][j] = 1 + dp[i - 1][j - 1];
			else dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
		}
	}

	return n - dp[n][n];
}

// Approach 2:
// Min del = n - lps
int minDeletions(string str, int n) {
	string rev = str;
	reverse(rev.begin(), rev.end());

	vector<int> prev(n + 1, 0), curr(n + 1, 0);

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (str[i - 1] == rev[j - 1]) curr[j] = 1 + prev[j - 1];
			else curr[j] = max(prev[j], curr[j - 1]);
		}
		prev = curr;
	}

	return n - prev[n];
}