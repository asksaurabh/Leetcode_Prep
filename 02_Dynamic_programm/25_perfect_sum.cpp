// COunt the number of subsets having sum k(>0). [Array elements can be zero]
#include <bits/stdc++.h>
using namespace std;

// Memo
int count(vector<int> &arr, int index, int k, vector<vector<int>> &dp) {

	if (index == 0) {
		if (k == 0 and arr[0] == 0) return 2;       // Eg. arr = {0}, k = 0
		if (k == 0 || k == arr[0]) return 1;        // Eg. arr = {5}, k = 0 and arr = {5}, k = 5
		return 0;

	}
	if (dp[index][k] != -1) return dp[index][k];

	if (arr[index] > k)
		return count(arr, index - 1, k, dp);

	return dp[index][k] = count(arr, index - 1, k, dp) + count(arr, index - 1, k - arr[index], dp);
}

// Tabulation
// int count(vector<int> &arr, int n, int k) {

//     vector<vector<int>> dp(n, vector<int> (k + 1, 0));
// 	if(arr[0] == 0) dp[0][0] = 2;
//     else dp[0][0] = 1;

// 	if (arr[0] != 0 and arr[0] <= k)
// 		dp[0][arr[0]] = 1;

// 	for (int i = 1; i < n; i++) {
// 		for (int j = 0; j <= k; j++) {

// 			if (arr[i] > j) dp[i][j] = dp[i - 1][j];
// 			else
// 				dp[i][j] = (dp[i - 1][j] + dp[i - 1][j - arr[i]]) % mod;
// 		}
// 	}

// 	return dp[n - 1][k];
// }

// Tabulation: (ANOTHER WAY)
// Idea is to count as usual. Then account for zeroes in the answer by multiplying with pow(2, count of zero).
int count1(vector<int> &arr, int n, int k) {
	vector<vector<int>> dp(n, vector<int> (k + 1, 0));

	for (int i = 0; i < n; i++)
		dp[i][0] = 1;

	if (arr[0] <= k)
		dp[0][arr[0]] = 1;

	for (int i = 1; i < n; i++) {
		for (int j = 1; j <= k; j++) {

			if (arr[i] > j) dp[i][j] = dp[i - 1][j];
			else
				dp[i][j] = dp[i - 1][j] + dp[i - 1][j - arr[i]];
		}
	}

	// Count zeroes
	int count = 0;
	for (int val : arr) count += (val == 0);

	return (1 << count) * dp[n - 1][k];
}

void countSubsets(vector<int> &arr, int n, int k) {

	// Memo
	vector<vector<int>> dp(n, vector<int> (k + 1, -1));
	cout << count(arr, n - 1, k, dp) << "\n";

	// Tabluation
	cout << count1(arr, n, k) << "\n";
}

int main() {
	// vector<int> arr = {0, 0, 1};
	// int k = 1;
	vector<int> arr = {2, 3, 5, 6, 8, 10};
	int k = 10;

	countSubsets(arr, arr.size(), k);
	return 0;
}