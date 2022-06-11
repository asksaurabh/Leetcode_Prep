// Approach 1: T.C -> O(n * m), S.C -> O(n * m)
// Diff btw lcs and lcsub
// lcsub -> T[i][j] - is the longest common substring which **ENDS at SUFFIX** a[0,i] and b[0,j]
// lcs -> S[i][j] - longest common subsequence UP TO w1[0,i] and w2[0,j]
int lcs(string &str1, string &str2) {
    int n = str1.length(), m = str2.length();
    vector<vector<int>> dp(n + 1, vector<int> (m + 1, 0));
    int result = 0;

    for (int i = 0; i <= n; i++)
        dp[i][0] = 0;
    for (int j = 0; j <= m; j++)
        dp[0][j] = 0;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {

            if (str1[i - 1] == str2[j - 1]) {
                dp[i][j] = 1 + dp[i - 1][j - 1];
                result = max(result, dp[i][j]);
            }
            else
                dp[i][j] = 0;
        }
    }

    return result;
}

// Approach 2: S.C -> O(m)
int lcs(string &str1, string &str2) {
    int n = str1.length(), m = str2.length();
    vector<int> prev(m + 1, 0), curr(m + 1, 0);
    int result = 0;

    for (int j = 0; j <= m; j++)
        prev[j] = 0;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {

            if (str1[i - 1] == str2[j - 1]) {
                curr[j] = 1 + prev[j - 1];
                result = max(result, curr[j]);
            }
            else
                curr[j] = 0;
        }
        prev = curr;
    }

    return result;
}