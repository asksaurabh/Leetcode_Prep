// Approach 1: words.size() -> n, words[i].size() -> m. -> T.C = O(nmlogm)
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


// Approach 2: Using count sort. T.C -> O(nm)
void sortKey(string &key) {
    vector<int> count(26, 0);

    for (char ch : key) {
        count[ch - 'a']++;
    }

    int k = 0;
    for (int i = 0; i < 26; i++) {
        if (count[i] > 0) {
            int freq = count[i];
            while (freq--) {
                key[k] = i + 'a';
                k++;
            }
        }
    }
}
vector<vector<int> > Solution::anagrams(const vector<string> &words) {
    vector<vector<int>> result;
    unordered_map<string, vector<int>> mp;

    int index = 1;
    for (string word : words) {
        string key = word;
        sortKey(key);
        mp[key].push_back(index);
        index++;
    }

    for (auto pr : mp) {
        result.push_back(pr.second);
    }

    return result;
}
