// MEMOIZATION -> O(n^3)
#include<bits/stdc++.h>
int solve(int i, int j, vector<int> &arr, vector<vector<int>> &dp) {
	if (i == j) return 0;
	if (dp[i][j] != -1) return dp[i][j];

	int res = INT_MAX;
	for (int k = i; k <= j - 1; k++) {
		int steps = arr[i - 1] * arr[k] * arr[j] + solve(i, k, arr, dp) + solve(k + 1, j, arr, dp);
		res = min(res, steps);
	}

	return dp[i][j] = res;
}
int matrixMultiplication(vector<int> &arr, int n) {
	int i = 1, j = n - 1;
	vector<vector<int>> dp(n, vector<int> (n, -1));
	return solve(i, j, arr, dp);
}

// TABULATION
#include<bits/stdc++.h>
int matrixMultiplication(vector<int> &arr, int n) {
//     int i = 1, j = n-1;
	vector<vector<int>> dp(n, vector<int> (n, 0));
// 	return solve(i, j, arr, dp);

	for (int i = 1; i <= n - 1; i++)
		dp[i][i] = 0;

	for (int i = n - 1; i >= 1; i--) {
		for (int j = i + 1; j <= n - 1; j++) {
			int res = INT_MAX;

			for (int k = i; k <= j - 1; k++) {
				int steps = arr[i - 1] * arr[k] * arr[j] + dp[i][k] + dp[k + 1][j];
				res = min(res, steps);
			}

			dp[i][j] = res;
		}
	}

	return dp[1][n - 1];
}