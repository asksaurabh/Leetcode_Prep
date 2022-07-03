// Memo + Rec
const int mod = 1e9 + 7;

int solve(int i, int sum, int *nums, vector<vector<int>> &dp) {
	if (i == 0) {
		if (sum == 0) return 1;
		else return 0;
	}
	if (dp[i][sum] != -1) return dp[i][sum];

	if (nums[i - 1] > sum) return dp[i][sum] = solve(i - 1, sum, nums, dp) % mod;
	return dp[i][sum] = (solve(i - 1, sum, nums, dp) +
	                     solve(i - 1, sum - nums[i - 1], nums, dp)) % mod;
}
int perfectSum(int arr[], int n, int sum) {
	vector<vector<int>> dp(n + 1, vector<int> (sum + 1, -1));
	return solve(n, sum, arr, dp);
}


// tabulation:
const int mod = 1e9 + 7;

int perfectSum(int nums[], int n, int sum) {
	vector<vector<int>> dp(n + 1, vector<int> (sum + 1, 0));

	dp[0][0] = 1;
	for (int j = 1; j <= sum; j++) dp[0][j] = 0;

	for (int i = 1; i <= n; i++) {
		for (int j = 0; j <= sum; j++) {
			if (nums[i - 1] > j) dp[i][j] = dp[i - 1][j];
			else dp[i][j] = (dp[i - 1][j] + dp[i - 1][j - nums[i - 1]]) % mod;
		}
	}

	return dp[n][sum];
}

// Space opt:
const int mod = 1e9 + 7;

int perfectSum(int nums[], int n, int sum) {

	vector<int> prev(sum + 1, 0), curr(sum + 1, 0);
	prev[0] = 1;

	for (int j = 1; j <= sum; j++) prev[j] = 0;

	for (int i = 1; i <= n; i++) {
		for (int j = 0; j <= sum; j++) {
			if (nums[i - 1] > j) curr[j] = prev[j];
			else curr[j] = (prev[j] + prev[j - nums[i - 1]]) % mod;
		}
		prev = curr;
	}

	return prev[sum];
}