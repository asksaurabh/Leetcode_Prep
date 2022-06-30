// Tabulation:
#include<bits/stdc++.h>
int minSubsetSumDifference(vector<int>& arr, int n)
{
	// Find the last row of the subset sum problem.
	// Tells me what all subset sum is possible considering all the elements
	int sum = 0;
	for (int val : arr) sum += val;
	vector<vector<int>> dp(n, vector<int> (sum + 1, 0));

	for (int i = 0; i < n; i++)
		dp[i][0] = 1;

	dp[0][arr[0]] = 1;

	for (int i = 1; i < n; i++) {
		for (int j = 1; j <= sum; j++) {
			if (arr[i] > j) dp[i][j] = dp[i - 1][j];
			else dp[i][j] = (dp[i - 1][j] || dp[i - 1][j - arr[i]]);
		}
	}

	// Got the last row. Now, iterate over half of it.
	int minDiff = INT_MAX;
	for (int i = 0; i <= sum / 2; i++) {
		if (dp[n - 1][i] == 1) {
			minDiff = min(minDiff, sum - 2 * i);
		}
	}
	return minDiff;
}

// Space optimized:
#include<bits/stdc++.h>
int minSubsetSumDifference(vector<int>& arr, int n)
{
	// Find the last row of the subset sum problem.
	// Tells me what all subset sum is possible considering all the elements
	int sum = 0;
	for (int val : arr) sum += val;
	vector<int> prev(sum + 1, 0), curr(sum + 1, 0);

	prev[0] = curr[0] = 1;
	prev[arr[0]] = 1;

	for (int i = 1; i < n; i++) {
		for (int j = 1; j <= sum; j++) {
			if (arr[i] > j) curr[j] = prev[j];
			else curr[j] = (prev[j] || prev[j - arr[i]]);
		}
		prev = curr;
	}

	// Got the last row. Now, iterate over half of it. If taht subset
	// sum is possible then choose which given abs min diff.
	int minDiff = INT_MAX;
	for (int i = 0; i <= sum / 2; i++) {
		if (prev[i] == 1) {
			minDiff = min(minDiff, sum - 2 * i);
		}
	}
	return minDiff;
}


// Previous Approaches:
// Tabulation:
int minSubsetSumDifference(vector<int>& arr, int n)
{
	// Find all possible subset sums that u can get after considering n elements of arr
	// This can be found out by the last row of the subset-sum dp
	int k = 0;
	for (int val : arr) k += val;

	vector<vector<int>> dp(n + 1, vector<int> (k + 1, 0));

	for (int i = 0; i <= n; i++) dp[i][0] = 1;
	for (int j = 1; j <= k; j++) dp[0][j] = 0;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= k; j++) {
			if (arr[i - 1] > j) dp[i][j] = dp[i - 1][j];
			else dp[i][j] = dp[i - 1][j - arr[i - 1]] || dp[i - 1][j];
		}
	}

	// In the last row -> all those subset sums are marked 1 which are possible to achieve
	// Choose which given min(abs(k - 2 * Si))

	int minSubsetSum = 1e9 + 7;
	for (int j = 0; j <= k; j++) {
		if (dp[n][j] == 1) {
			minSubsetSum = min(minSubsetSum, abs(k - 2 * j));
		}
	}

	return minSubsetSum;
}
