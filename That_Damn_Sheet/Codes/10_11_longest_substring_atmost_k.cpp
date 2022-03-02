#include <bits/stdc++.h>
using namespace std;

int getLength(string s, int k) {
    int n = s.length();
    unordered_map<char, int> mp;
    int i = 0, j = 0;
    int maxLength = 0;

    while (j < n) {
        mp[s[j]]++;

        if (mp.size() <= k) {
            maxLength = max(maxLength, j - i + 1);
            j++;
        }

        else if (mp.size() > k) {
            while (mp.size() > k) {
                mp[s[i]]--;
                if (mp[s[i]] == 0)
                    mp.erase(s[i]);
                i++;
            }

            if (mp.size() <= k) {
                maxLength = max(maxLength, j - i + 1);
            }

            j++;
        }
    }

    return maxLength;
}
int main() {
    string s = "aabcbcdbca";
    cout << getLength(s, 2);
}
