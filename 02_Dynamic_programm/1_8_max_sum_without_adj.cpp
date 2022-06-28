// Top-Down
int solve(int n, int *arr, vector<int> &dp) {
	if (n == 0) return 0;
	if (n == 1) return arr[0];
	if (dp[n] != -1) return dp[n];

	int take = arr[n - 1] + solve(n - 2, arr, dp);
	int notTake = solve(n - 1, arr, dp);

	return dp[n] = max(take, notTake);
}
// calculate the maximum sum with out adjacent
int findMaxSum(int *arr, int n) {
	// code here
	vector<int> dp(n + 1, -1);
	return solve(n, arr, dp);
}

// Bottom-Up
int findMaxSum(int *arr, int n) {
	// code here
	vector<int> dp(n + 1, 0);
	if (n == 0) return 0;

	dp[1] = arr[0];
	for (int i = 2; i <= n; i++) {
		int take = arr[i - 1] + dp[i - 2];
		int notTake = dp[i - 1];
		dp[i] = max(take, notTake);
	}

	return dp[n];
}

// Approach: Space Optimized
int findMaxSum(int *arr, int n) {
	if (n == 0) return 0;

	int a = 0, b = arr[0];

	for (int i = 2; i <= n; i++) {
		int take = arr[i - 1] + a;
		int notTake = b;
		int maxSum = max(take, notTake);

		a = b;
		b = maxSum;
	}

	return b;
}