#include <bits/stdc++.h>
using namespace std;

int countWays(int n, int k, vector<int> &dp) {

    if (n < 0) return 0;
    if (n == 0) return 1;
    if (n == 1) return 1;

    if (dp[n] != -1) return dp[n];

    int count = 0;
    for (int step = 1; step <= k; step++) {
        count += countWays(n - step, k, dp);
    }

    return dp[n] = count;
}

int main() {
    int n, k;
    cin >> n >> k;

    vector<int> dp(n + 1, -1);
    cout << countWays(n, k, dp);
}

// n = 4, k = 3, O/P -> 7