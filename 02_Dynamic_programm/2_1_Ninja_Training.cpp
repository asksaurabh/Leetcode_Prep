// Offset 0 approach:
// Top-Down
#define vvi vector<vector<int>>
#define vi vector<int>
int getMaxPoints(int day, int lastTask, vvi &points, vvi &dp) {
	if (day == 0) return 0;    // Training has not started yet. No training no tasks no points.
	if (dp[day][lastTask] != -1) return dp[day][lastTask];

	int maxPoints = 0;
	for (int task = 0; task < 3; task++) {
		if (task != lastTask) {
			int currPoints = points[day - 1][task] + getMaxPoints(day - 1, task, points, dp);
			maxPoints = max(maxPoints, currPoints);
		}
	}

	return dp[day][lastTask] = maxPoints;
}
int ninjaTraining(int n, vector<vector<int>> &points)
{
	// Variables changing: day and task no.
	vvi dp(n + 1, vector<int> (4, -1));
	return getMaxPoints(n, 3, points, dp);
}

// Top-Down Approach
int solve(int day, int lastTask, vector<vector<int>> &dp, vector<vector<int>> &points) {
	if (day == 0) {
		int maxi = 0;
		for (int task = 0; task < 3; task++) {
			if (task != lastTask)
				maxi = max(maxi, points[0][task]);
		}
		return maxi;
	}
	if (dp[day][lastTask] != -1) return dp[day][lastTask];

	int maxPoints = 0;
	for (int task = 0; task < 3; task++) {
		if (task != lastTask) {
			int point = points[day][task] + solve(day - 1, task, dp, points);
			maxPoints = max(maxPoints, point);
		}
	}

	return dp[day][lastTask] = maxPoints;
}
int ninjaTraining(int n, vector<vector<int>> &points) {
	vector<vector<int>> dp(n, vector<int> (4, -1));
	// Task lies btw 0..2
	// Task - 3 initially meaing no task picked till now.
	return solve(n - 1, 3, dp, points);
}

// Bottom-Up
int ninjaTraining(int n, vector<vector<int>> &points) {
	vector<vector<int>> dp(n, vector<int> (4, 0));
	// What is the max points u can gain on day i if task done previously was j.
	dp[0][0] = max(points[0][1], points[0][2]);
	dp[0][1] = max(points[0][0], points[0][2]);
	dp[0][2] = max(points[0][0], points[0][1]);
	dp[0][3] = max({points[0][0], points[0][1], points[0][2]});

	int maxPoints = 0;
	for (int day = 1; day < n; day++) {
		for (int lastTask = 0; lastTask < 4; lastTask++) {
			dp[day][lastTask] = 0;

			for (int task = 0; task < 3; task++) {
				if (task != lastTask) {
					int point = points[day][task] + dp[day - 1][task];
					dp[day][lastTask] = max(dp[day][lastTask], point);
				}
			}
		}
	}

	return dp[n - 1][3];
}

// Space Optimized.
#include<bits/stdc++.h>
int ninjaTraining(int n, vector<vector<int>> &points) {

	vector<int> prev(4, 0), curr(4, 0);
	// What is the max points u can gain on day i if task done previously was j.
	prev[0] = max(points[0][1], points[0][2]);
	prev[1] = max(points[0][0], points[0][2]);
	prev[2] = max(points[0][0], points[0][1]);
	prev[3] = max({points[0][0], points[0][1], points[0][2]});

	int maxPoints = 0;
	for (int day = 1; day < n; day++) {
		for (int lastTask = 0; lastTask < 4; lastTask++) {
			curr[lastTask] = 0;

			for (int task = 0; task < 3; task++) {
				if (task != lastTask) {
					int point = points[day][task] + prev[task];
					curr[lastTask] = max(curr[lastTask], point);
				}
			}
		}

		prev = curr;
	}

	return prev[3];
}