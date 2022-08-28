int Solution::solve(string A) {
    unordered_map<char, int> mp;

    for (char ch : A) {
        mp[ch]++;
    }

    int oddCount = 0;
    for (auto pr : mp) {
        if (pr.second & 1) oddCount++;
        if (oddCount > 1) return false;
    }

    return true;
}
