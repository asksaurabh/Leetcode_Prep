// Recursion + Memo
// #include<bits/stdc++.h>

// T.C -> O(m*3^(n*m))
// // Figure out max Path in order to reach row and col from any cell in first row.

#include<bits/stdc++.h>
int solve(int row, int col, vector<vector<int>> &matrix, vector<vector<int>> &dp) {
//     if(row < 0 || col < 0 || col >= matrix[0].size()) return -1e9 + 7;
	if (row == 0) return matrix[row][col];
	if (dp[row][col] != -1) return dp[row][col];

	int up = -1e9 + 7, upLeft = -1e9 + 7, upRight = -1e9 + 7;
	if (row > 0)
		up = matrix[row][col] + solve(row - 1, col, matrix, dp);
	if (row > 0 and col > 0)
		upLeft = matrix[row][col] + solve(row - 1, col - 1, matrix, dp);
	if (row > 0 and col < matrix[0].size() - 1)
		upRight = matrix[row][col] + solve(row - 1, col + 1, matrix, dp);

	dp[row][col] = max(up, max(upLeft, upRight));
}
int getMaxPathSum(vector<vector<int>> &matrix)
{
	int n = matrix.size(), m = matrix[0].size();
	vector<vector<int>> dp(n, vector<int> (m, -1));
	int maxSum = INT_MIN;
	for (int j = 0; j < m; j++) {
		int sum = solve(n - 1, j, matrix, dp);
		maxSum = max(maxSum, sum);
	}

	return maxSum;
}



// Approach 2: Tabulation.
// # include<bits/stdc++.h>
// int getMaxPathSum(vector<vector<int>> &matrix)
// {
//     int n = matrix.size();
//     int m = matrix[0].size();

//     vector<vector<int>> dp(n, vector<int> (m, 0));

//     for(int i = 0; i < n; i++) {
// 		for(int j = 0; j < m; j++) {

//             if(i == 0) dp[i][j] = matrix[i][j];
//             else {
//                 int up = 0, upLeft = -1e9, upRight = -1e9;
//                 up = matrix[i][j] + dp[i - 1][j];
//                 if(j > 0) upLeft = matrix[i][j] + dp[i-1][j-1];
//                 if(j < m - 1) upRight = matrix[i][j] + dp[i-1][j+1];

//                 dp[i][j] = max(up, max(upLeft, upRight));
//             }
//         }
//     }

//     int maxPathSum = INT_MIN;
//     for(int j = 0; j < m; j++) {
//         maxPathSum = max(maxPathSum, dp[n-1][j]);
//     }

//     return maxPathSum;
// }



// Approach 3: Space optimization
// # include<bits/stdc++.h>
// int getMaxPathSum(vector<vector<int>> &matrix)
// {
//     int n = matrix.size();
//     int m = matrix[0].size();
//     vector<int> prevrow(m, 0);

//     for(int i = 0; i < n; i++) {
//         vector<int> curr_row(m, 0);
// 		for(int j = 0; j < m; j++) {

//             if(i == 0) curr_row[j] = matrix[i][j];
//             else {
//                 int up = 0, upLeft = -1e9, upRight = -1e9;
//                 up = matrix[i][j] + prevrow[j];
//                 if(j > 0) upLeft = matrix[i][j] + prevrow[j-1];
//                 if(j < m - 1) upRight = matrix[i][j] + prevrow[j+1];

//                 curr_row[j] = max(up, max(upLeft, upRight));
//             }
//         }
//         prevrow = curr_row;
//     }

//     int maxPathSum = INT_MIN;
//     for(int j = 0; j < m; j++) {
//         maxPathSum = max(maxPathSum, prevrow[j]);
//     }

//     return maxPathSum;
// }