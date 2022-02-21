struct Node {
    Node* links[26];
    bool flag = false;
};
class Trie {
    Node* root;
public:
    Trie() {
        root = new Node();
    }
    void insert(string &word) {
        Node* temp = root;
        for (char ch : word) {
            if (temp->links[ch - 'a'] == nullptr)
                temp->links[ch - 'a'] = new Node();

            temp = temp->links[ch - 'a'];
        }

        // Word is completely inserted.
        temp->flag = true;
    }

    bool areAllPrefixPresent(string &word) {
        Node* temp = root;
        for (int i = 0; i < word.length(); i++) {
            temp = temp->links[word[i] - 'a'];

            // Is prefix from [0..i] present i array?
            if (temp->flag == false)
                return false;
        }

        return true;
    }
};
string completeString(int n, vector<string> &a) {
    Trie t;

    // Time Compl -> O(a.size()) * O(len of string)
    for (string word : a) {
        t.insert(word);
    }

    // Check complete string
    // Time compl -> O(a.size() * O(len of a[i]))
    string res = "";
    for (string word : a) {
        if (t.areAllPrefixPresent(word) == true) {
            if (word.length() > res.length())
                res = word;
            else if ((word.length() == res.length()) and word < res)
                res = word;
        }
    }

    return res == "" ? "None" : res;
}