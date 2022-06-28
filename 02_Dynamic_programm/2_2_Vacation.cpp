#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define FAST_IO ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
typedef long long ll;
typedef long double lld;

// Rec + Memo
// ll solve(int day, int lastTask, vector<vector<ll>> &arr, vector<vector<ll>> &dp) {

// 	if (day == 0) {
// 		ll maxi = 0;
// 		for (int task = 0; task < 3; task++)
// 			if (task != lastTask)
// 				maxi = max(maxi, arr[0][task]);
// 		return maxi;
// 	}
// 	if (dp[day][lastTask] != -1) return dp[day][lastTask];

// 	ll maxPoints = 0;
// 	for (int task = 0; task < 3; task++) {
// 		if (task != lastTask) {
// 			ll points = arr[day][task] + solve(day - 1, task, arr, dp);
// 			maxPoints = max(maxPoints, points);
// 		}
// 	}

// 	return dp[day][lastTask] = maxPoints;
// }

// Top-Down
ll approach2(int n, vector<vector<ll>> &arr) {
	vector<vector<ll>> dp(n, vector<ll> (4, 0));

	dp[0][0] = max(arr[0][1], arr[0][2]);
	dp[0][1] = max(arr[0][0], arr[0][2]);
	dp[0][2] = max(arr[0][1], arr[0][0]);
	dp[0][3] = max({arr[0][1], arr[0][0], arr[0][2]});

	for (int day = 1; day < n; day++) {
		for (int lastTask = 0; lastTask < 4; lastTask++) {

			for (int task = 0; task < 3; task++) {
				if (task != lastTask) {
					ll points = arr[day][task] + dp[day - 1][task];
					dp[day][lastTask] = max(dp[day][lastTask], points);
				}
			}

		}
	}

	return dp[n - 1][3];
}

int main() {

	FAST_IO;
	int t = 1;

	while (t--) {
		ll n;
		cin >> n;

		// each day has 3 activities.
		vector<vector<ll>> arr(n, vector<ll> (3, 0));
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < 3; j++) {
				cin >> arr[i][j];
			}
		}

		// dp[i][j] -> max points gained on day i if prev task was j.
		// I have 3 tasks(0..2). I will use task = 3 to say no task taken till now.
		// vector<vector<ll>> dp(n, vector<ll> (4, -1));

		// What is the max point u can gain till day n-1 if u have taken no job till now.
		// cout << solve(n - 1, 3, arr, dp) << "\n";
		cout << approach2(n, arr);
	}

	return 0;
}