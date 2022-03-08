class Solution
{
public:
	//Function to find length of shortest common supersequence of two strings.
	int shortestCommonSupersequence(string x, string y, int n, int m)
	{
		// Find LCS of x and y
		// Ans -> x + y - lcs

		vector<vector<int>> dp(n + 1, vector<int> (m + 1, 0));

		for (int i = 0; i <= n; i++)
			dp[i][0] = 0;
		for (int j = 0; j <= m; j++)
			dp[0][j] = 0;

		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= m; j++) {

				if (x[i - 1] == y[j - 1]) dp[i][j] = 1 + dp[i - 1][j - 1];
				else dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
			}
		}

		return n + m - dp[n][m];
	}
};

// Approach 2: Space Optimized
class Solution
{
public:
	//Function to find length of shortest common supersequence of two strings.
	int shortestCommonSupersequence(string x, string y, int n, int m)
	{
		// Find LCS of x and y
		// Ans -> x + y - lcs

		vector<int> prev(m + 1, 0), curr(m + 1, 0);

		for (int j = 0; j <= m; j++)
			prev[j] = 0;

		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= m; j++) {

				if (x[i - 1] == y[j - 1]) curr[j] = 1 + prev[j - 1];
				else curr[j] = max(prev[j], curr[j - 1]);
			}
			prev = curr;
		}

		return n + m - prev[m];
	}
};