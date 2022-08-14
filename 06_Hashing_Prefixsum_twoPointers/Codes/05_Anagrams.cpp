vector<vector<int> > Solution::anagrams(const vector<string> &words) {
    unordered_map<string, vector<int> > mp;
    vector<vector<int> > res;

    // Idea is to group by their sorted keys
    int index = 1;
    for (string word : words) {
        string key = word;
        sort(key.begin(), key.end());
        mp[key].push_back(index);
        index++;
    }

    for (auto pr : mp) {
        res.push_back(pr.second);
    }

    return res;
}
