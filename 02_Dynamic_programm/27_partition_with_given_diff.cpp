const int mod = (int)(1e9 + 7);
// int count(vector<int> &arr, int index, int k, vector<vector<int>> &dp) {
// 	if (index == 0) {
// 		if (k == 0 and arr[0] == 0) return 2;       // Eg. arr = {0}, k = 0
// 		if (k == 0 || k == arr[0]) return 1;        // Eg. arr = {5}, k = 0 and arr = {5}, k = 5
// 		return 0;
// 	}
// 	if (dp[index][k] != -1) return dp[index][k];

// 	if (arr[index] > k)
// 		return count(arr, index - 1, k, dp);

// 	return dp[index][k] = (count(arr, index - 1, k, dp) + count(arr, index - 1, k - arr[index], dp)) % mod;
// }

// Tabulation
// int count1(vector<int> &arr, int n, int k) {

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

// Space optimization
int count2(vector<int> &arr, int n, int k) {

//     vector<vector<int>> dp(n, vector<int> (k + 1, 0));
	vector<int> prevrow(k + 1, 0), currrow(k + 1, 0);
	if (arr[0] == 0) {
		prevrow[0] = currrow[0] = 2;
	}
	else prevrow[0] = currrow[0] = 1;

	if (arr[0] != 0 and arr[0] <= k)
		prevrow[arr[0]] = 1;

	for (int i = 1; i < n; i++) {
		for (int j = 0; j <= k; j++) {

			if (arr[i] > j) currrow[j] = prevrow[j];
			else
				currrow[j] = (prevrow[j] + prevrow[j - arr[i]]) % mod;
		}
		prevrow = currrow;
	}

	return prevrow[k];
}

int countPartitions(int n, int d, vector<int> &arr) {
	int totalSum = 0;
	for (int val : arr) totalSum += val;

	// Question boils down to count subsets with sum = (totalSum - D)/2;
	int k = (totalSum - d) / 2;

	// (totalSum - d)/2 has to be evenly divisible and totalSum - d can't be negative
	if ((totalSum - d) % 2 or (totalSum - d) < 0) return 0;

	vector<vector<int>> dp(n, vector<int> (k + 1, -1));
//     return count1(arr, n , k);
//     return count(arr, n -1, k, dp);
	return count2(arr, n, k);
}


