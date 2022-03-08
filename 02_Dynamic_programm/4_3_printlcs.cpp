#include <bits/stdc++.h>
using namespace std;

int lcs(int n, int m, string &s1, string &s2, vector<vector<int>> &dp) {
    if (n == 0 || m == 0) return 0;
    if (dp[n][m] != -1) return dp[n][m];

    if (s1[n - 1] == s2[m - 1]) return dp[n][m] = 1 + lcs(n - 1, m - 1, s1, s2, dp);
    return dp[n][m] = max(lcs(n - 1, m, s1, s2, dp), lcs(n, m - 1, s1, s2, dp));
}

// T.C -> O(n + m)
void printlcs(string &s1, string &s2) {
    int n = s1.length(), m = s2.length();
    vector<vector<int>> dp(n + 1, vector<int> (m + 1, -1));
    lcs(n, m, s1, s2, dp);

    // Now once we filled the dp array
    int i = n, j = m;
    string result = "";
    while (i > 0 and j > 0) {
        if (s1[i - 1] == s2[j - 1]) {
            result += s1[i - 1];
            i--, j--;
        }
        else {
            // Where to move when characters are not equal
            if (dp[i - 1][j] > dp[i][j - 1])
                i--;
            else
                j--;
        }
    }

    reverse(result.begin(), result.end());
    cout << result;

}
int main() {
    string s1 = "acbcf";
    string s2 = "abcdaf";

    printlcs(s1, s2);
}
