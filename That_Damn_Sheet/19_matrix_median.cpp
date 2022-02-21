// Approach 1:
// 1. Create a vector of size m*n and store all elements here. S.C -> O(m*n)
// 2. Sort the vector T.C -> O((mn * log(mn))
// 3. Return the middle element of the vector.
// T.C -> O(mn * log(mn)), S.C -> O(m*n)

//Approach 2:
// Let matrix[i][j] lies btw [0..N]
// Time Complexity -> O(log(N)) * O(rows * log(columns))

// Comes a sorted array, find the ceiling of target to find the numbers less than target
// You have to find strict ceiling(means num > target even if target is present in array)
int countNumbersLessThanMid(vector<int> &row, int target) {
	int st = 0;
	int end = row.size() - 1;

	while (st <= end) {
		int mid = st + (end - st) / 2;
		if (row[mid] <= target)
			st = mid + 1;
		else
			end = mid - 1;
	}

	// In the end start points to the ceiling.
	return st;
}
int getMedian(vector<vector<int>> &matrix)
{
	// Our number lies btw [1..10^5]
	// So our search space for median lies somwhere between 1..1e6

	int start = 1;
	int end = 1e5;
	int n = matrix.size();
	int m = matrix[0].size();

	while (start <= end) {
		int mid = start + (end - start) / 2;

		// Median lies in the middle.
		// So count the number of elements that is <= curr median(mid).
		int count = 0;
		for (int i = 0; i < n; i++)
			count += countNumbersLessThanMid(matrix[i], mid);

		// Since, Median lies in the middle.
		// Better understood if u dry run. In the end, 'start' points to the median.
		if (count <= (n * m) / 2) start = mid + 1;
		else end = mid - 1;
	}

	return start;
}