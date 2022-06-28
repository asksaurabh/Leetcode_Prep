#include <bits/stdc++.h>
using namespace std;
#define FAST_IO ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)

// Top-Down
// Req: vector<int> dp(n + 1, -1);
// int solve(int n, int k, vector<int> &dp, vector<int> &heights) {
// 	if (n == 1) return 0;
// 	if (n == 2) return abs(heights[2] - heights[1]);
// 	if (dp[n] != -1) return dp[n];

// 	int minCost = INT_MAX;
// 	for (int jump = 1; jump <= k; jump++) {
// 		if (n - jump <= 0) break;

// 		int cost = solve(n - jump, k, dp, heights) + abs(heights[n] - heights[n - jump]);
// 		minCost = min(minCost, cost);
// 	}

// 	return dp[n] = minCost;
// }


// Bottom-Up
// Req: vector<int> dp(n + 1, 0);
int solve(int n, int k, vector<int> &dp, vector<int> &heights) {
	if (n == 1) return 0;

	dp[1] = 0, dp[2] = abs(heights[2] - heights[1]);
	int minCost = INT_MAX;

	for (int i = 3; i <= n; i++) {
		int minCost = INT_MAX;
		for (int jump = 1; jump <= k; jump++) {
			if (i - jump <= 0) break;

			int cost = dp[i - jump] + abs(heights[i] - heights[i - jump]);
			minCost = min(minCost, cost);
		}

		dp[i] = minCost;
	}

	return dp[n];
}

int main() {

	FAST_IO;
	int t = 1;

	while (t--) {
		int n, k;
		cin >> n >> k;

		vector<int> heights(n + 1);
		heights[0] = 0;

		for (int i = 1; i <= n; i++)
			cin >> heights[i];

		vector<int> dp(n + 1, 0);
		cout << solve(n, k, dp, heights);
	}

	return 0;
}