// Approach 1: S.C -> O(n * m)
class Solution {
public:
	int minOperations(string x, string y)
	{
		// Find LCS of x and y
		// X -> LCS == x.length - lcs (min del)
		// LCS -> Y == y.length - lcs (min ins)
		// Total oprs -> x.length + y.length - 2lcs

		int n = x.length(), m = y.length();
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

		return (n + m - 2 * dp[n][m]);
	}
};

// Approach 2: S.C -> O(m)
class Solution {
public:
	int minOperations(string x, string y)
	{
		// Find LCS of x and y
		// X -> LCS == x.length - lcs (min del)
		// LCS -> Y == y.length - lcs (min ins)
		// Total oprs -> x.length + y.length - 2lcs

		int n = x.length(), m = y.length();
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

		return (n + m - 2 * prev[m]);
	}
};