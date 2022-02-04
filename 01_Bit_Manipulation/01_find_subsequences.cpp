#include <bits/stdc++.h>
using namespace std;

void generateAllSubsequences(string s, int n, vector<string> &subs) {

    int totalSubsets = (1 << n);
    for (int i = 0; i < totalSubsets; i++) {
        string t = "";
        int num = i;

        int pos = 0;
        while (num > 0) {
            int lb = (num & 1);
            num = num >> 1;

            if (lb == 1) t.push_back(s[pos]);
            pos++;
        }

        if (t != "")
            subs.push_back(t);
        else
            subs.push_back("NULL");
    }
}

int main() {
    string s;
    s = "abc";

    vector<string> subs;
    generateAllSubsequences(s, s.length(), subs);

    for (string s : subs)
        cout << s << "\n";

    return 0;
}
