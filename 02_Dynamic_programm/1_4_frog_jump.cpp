// Top-Down
int solve(int n, vector<int> &dp, vector<int> &heights) {
	if (n == 1) return 0;
	if (n == 2) return abs(heights[1] - heights[0]);
	if (dp[n] != -1) return dp[n];

	return dp[n] = min(solve(n - 1, dp, heights) + abs(heights[n - 1] - heights[n - 2]), solve(n - 2, dp, heights) + abs(heights[n - 1] - heights[n - 3]));
}
int frogJump(int n, vector<int> &heights)
{
	vector<int> minEnergyLostToReach(n + 1, -1);
	return solve(n, minEnergyLostToReach, heights);
}

// Bottom-Up
int frogJump(int n, vector<int> &heights)
{
	vector<int> minEnergyLostToReach(n + 1, 0);
	if (n == 1) return 0;

	minEnergyLostToReach[1] = 0;
	minEnergyLostToReach[2] = abs(heights[1] - heights[0]);

	for (int i = 3; i <= n; i++) {
		minEnergyLostToReach[i] = min(minEnergyLostToReach[i - 1] + abs(heights[i - 1] - heights[i - 2]), minEnergyLostToReach[i - 2] + abs(heights[i - 1] - heights[i - 3]));
	}

	return minEnergyLostToReach[n];
}

// Space Optimized
int frogJump(int n, vector<int> &heights)
{
	if (n == 1) return 0;

	int a = 0;
	int b = abs(heights[1] - heights[0]);

	for (int i = 3; i <= n; i++) {
		int c = min(a + abs(heights[i - 1] - heights[i - 3]), b + abs(heights[i - 1] - heights[i - 2]));

		a = b;
		b = c;
	}

	return b;
}