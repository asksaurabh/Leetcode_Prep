//Top-Down
const int mod = 1e9 + 7;
int solve(int row, int col, vector<vector<int>> &mat, vector<vector<int>> &dp) {
	if (row < 0 || col < 0 || mat[row][col] == -1) return 0;
	if (row == 0 and col == 0) return 1;
	if (dp[row][col] != -1) return dp[row][col];

	int up = 0, left = 0;
	up = solve(row - 1, col, mat, dp);
	left = solve(row, col - 1, mat, dp);

	return dp[row][col] = (up + left) % mod;
}
int mazeObstacles(int n, int m, vector< vector< int> > &mat) {
	vector<vector<int>> dp(n, vector<int> (m, -1));
	return solve(n - 1, m - 1, mat, dp);
}

// Bottom-Up
const int mod = 1e9 + 7;
int mazeObstacles(int n, int m, vector< vector< int> > &mat) {
	vector<vector<int>> dp(n, vector<int> (m, 0));

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (mat[i][j] == -1) dp[i][j] = 0;
			else if (i == 0 and j == 0) dp[i][j] = 1;
			else {
				int up = 0, left = 0;
				if (i > 0) up = dp[i - 1][j];
				if (j > 0) left = dp[i][j - 1];
				dp[i][j] = (up + left) % mod;
			}
		}
	}

	return dp[n - 1][m - 1];
}

// Space Optimized
const int mod = 1e9 + 7;
int mazeObstacles(int n, int m, vector< vector< int> > &mat) {
	vector<vector<int>> dp(n, vector<int> (m, 0));
	vector<int> prev(m, 0), curr(m, 0);
	prev[0] = 1;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (mat[i][j] == -1) curr[j] = 0;
			else if (i == 0 and j == 0) curr[j] = 1;
			else {
				int up = 0, left = 0;
				if (i > 0) up = prev[j];
				if (j > 0) left = curr[j - 1];
				curr[j] = (left + up) % mod;
			}
		}
		prev = curr;
	}

	return prev[m - 1];
}