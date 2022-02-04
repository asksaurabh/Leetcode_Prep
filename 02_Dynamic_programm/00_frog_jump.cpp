#include <iostream>
using namespace std;

// Top Down approach
// See how I passed last element index instead of size so that I could stop worrying about indicies and think clearly.

int minEnergy(int n, vector<int> &dp, vector<int> &heights) {
	if (n == 0) return 0;
	if (n == 1) return abs(heights[1] - heights[0]);
	if (dp[n] != -1) return dp[n];

	int left = minEnergy(n - 1, dp, heights) + abs(heights[n] - heights[n - 1]);
	int right = minEnergy(n - 2, dp, heights) + abs(heights[n] - heights[n - 2]);

	return dp[n] = min(left, right);
}

int frogJump(int n, vector<int> &heights)
{
	vector<int> dp(n + 1, -1);
	int lastIndex = n - 1;
	return minEnergy(lastIndex, dp, heights);
}


// Bottom Up

int frogJump(int n, vector<int> &heights)
{
	vector<int> dp(n + 1, -1);
	dp[0] = 0, dp[1] = abs(heights[1] - heights[0]);

	for (int stair = 2; stair < n; stair++) {
		int left = dp[stair - 1] + abs(heights[stair] - heights[stair - 1]);
		int right = dp[stair - 2] + abs(heights[stair] - heights[stair - 2]);

		dp[stair] = min(left, right);
	}

	return dp[n - 1];
}

// Space Optimized

int frogJump(int n, vector<int> &heights) {
	if (n == 1) return 0;
	int prevprev = 0;
	int prev = abs(heights[1] - heights[0]);

	for (int i = 2; i < n; i++) {
		int left = prev + abs(heights[i] - heights[i - 1]);
		int right = prevprev + abs(heights[i] - heights[i - 2]);

		prevprev = prev;
		prev = min(left, right);
	}

	return prev;
}