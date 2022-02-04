#include <bits/stdc++.h>
using namespace std;

// TOP DOWN

// int frogJump(int index, int k, vector<int> &height, vector<int> &dp) {

// 	if (index == 0) return 0;
// 	if (index == 1) return abs(height[1] - height[0]);
// 	if (dp[index] != -1) return dp[index];

// 	int minCost = INT_MAX;
// 	for (int step = 1; step <= k; step++) {
// 		if (index - step < 0)
// 			break;

// 		// Take the jump
// 		int cost = frogJump(index - step, k, height, dp) + abs(height[index] - height[index - step]);
// 		minCost = min(minCost, cost);
// 	}

// 	return dp[index] = minCost;
// }

// BOTTOM UP

// int frogJump1(int n, int k, vector<int> &height, vector<int> &dp) {

// 	dp[0] = 0, dp[1] = abs(height[1] - height[0]);
// 	for (int stair = 2; stair < n; stair++) {
// 		for (int step = 1; step <= k; step++) {

// 			if (stair - step < 0)
// 				break;

// 			int cost = dp[stair - step] + abs(height[stair] - height[stair - step]);
// 			dp[stair] = dp[stair] == -1 ? cost : min(cost, dp[stair]);
// 		}

// 	}

// 	return dp[n - 1];
// }

int main() {
	int n, k;
	cin >> n >> k;

	vector<int> height(n);
	for (int i = 0; i < n; i++)
		cin >> height[i];

	vector<int> dp(n + 1, -1);
	// cout << frogJump(n - 1, k, height, dp);
	// cout << frogJump1(n, k, height, dp);


	return 0;
}