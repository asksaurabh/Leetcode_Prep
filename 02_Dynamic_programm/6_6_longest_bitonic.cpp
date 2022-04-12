#include<bits/stdc++.h>
int longestBitonicSequence(vector<int>& arr, int n) {
// 	lbs = lis from start + lis from end - 1
	vector<int> dp(n, 1), dp2(n, 1);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < i; j++) {
			if (arr[j] < arr[i] and dp[j] + 1 > dp[i])
				dp[i] = dp[j] + 1;
		}
	}

	for (int i = n - 1; i >= 0; i--) {
		for (int j = n - 1; j > i; j--) {
			if (arr[j] < arr[i] and dp2[j] + 1 > dp2[i])
				dp2[i] = dp2[j] + 1;
		}
	}

	int res = 0;
	for (int i = 0; i < n; i++)
		res = max(res, dp[i] + dp2[i] - 1);

	return res;
}
