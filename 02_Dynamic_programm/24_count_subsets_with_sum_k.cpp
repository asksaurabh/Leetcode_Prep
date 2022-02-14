// COunt the number of subsets having sum k(>0). [Array elements can't be zero]
#include <bits/stdc++.h>
using namespace std;

// Memo
int count(vector<int> &arr, int index, int k, vector<vector<int>> &dp) {

	if (k == 0) return 1;
	if (index == 0) return (arr[0] == k);
	if (dp[index][k] != -1) return dp[index][k];

	if (arr[index] > k)
		return count(arr, index - 1, k, dp);

	return dp[index][k] = count(arr, index - 1, k, dp) + count(arr, index - 1, k - arr[index], dp);
}

// tabulation
int count1(vector<int> &arr, int n, int k) {
	vector<vector<int>> dp(n, vector<int> (k + 1, 0));

	for (int i = 0; i < n; i++)
		dp[i][0] = 1;

	if (arr[0] <= k) {
		// arr = {8, 1, 3, 3}; k = 1;, dp[0][8] won't exist
		dp[0][arr[0]] = 1;
	}

	for (int i = 1; i < n; i++) {
		for (int j = 1; j <= k; j++) {

			if (arr[i] > j) dp[i][j] = dp[i - 1][j];
			else
				dp[i][j] = dp[i - 1][j] + dp[i - 1][j - arr[i]];
		}
	}

	return dp[n - 1][k];
}

// Space optimization
int count2(vector<int> &arr, int n, int k) {
	vector<int> prevrow(k + 1, 0), currrow(k + 1, 0);

	prevrow[0] = currrow[0] = 1;

	if (arr[0] <= k) {
		prevrow[arr[0]] = 1;
	}

	for (int i = 1; i < n; i++) {
		for (int j = 1; j <= k; j++) {

			if (arr[i] > j) currrow[j] = prevrow[j];
			else
				currrow[j] = prevrow[j] + prevrow[j - arr[i]];
		}
		prevrow = currrow;
	}

	return prevrow[k];
}

void countSubsets(vector<int> &arr, int n, int k) {

	// Memo
	vector<vector<int>> dp(n, vector<int> (k + 1, -1));
	cout << count(arr, n - 1, k, dp) << "\n";

	// Tabluation
	cout << count1(arr, n, k) << "\n";

	// Space Optimization
	cout << count2(arr, n, k) << "\n";
}

int main() {
	vector<int> arr = {2, 1, 3, 3};
	// vector<int> arr = {2, 3, 5, 6, 8, 10};
	int k = 6;
	// int k = 10;

	countSubsets(arr, arr.size(), k);
	return 0;
}