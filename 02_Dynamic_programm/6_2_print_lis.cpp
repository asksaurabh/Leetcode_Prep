#include <bits/stdc++.h>
using namespace std;

void printLIS(vector<int> &arr, int n) {
	vector<int> dp(n, 1), hash(n);
	for (int i = 0; i < n; i++)
		hash[i] = i;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < i; j++) {
			if (arr[j] < arr[i]) {
				if (dp[j] + 1 > dp[i]) {
					dp[i] = dp[j] + 1;
					hash[i] = j;
				}
			}
		}
	}

	int res = 0;
	for (int i = 0; i < n; i++) {
		if (dp[i] > dp[res])
			res = i;
	}

	// Print LIS
	cout << arr[res] << " ";
	while (hash[res] != res) {
		res = hash[res];
		cout << arr[res] << " ";
	}
}

int main() {
	vector<int> arr = {10, 9, 2, 5, 3, 7, 101, 18};
	int n = arr.size();

	printLIS(arr, n);
	return 0;
}