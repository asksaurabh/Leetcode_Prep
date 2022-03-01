struct Node {
    Node* links[26];
};

class Trie {
    Node* root;
public:
    Trie() {
        root = new Node();
    }

    // count only when the substring is not present.
    void insert(string &s, int &count) {
        Node* temp = root;
        for (char ch : s) {
            if (temp->links[ch - 'a'] == nullptr) {
                temp->links[ch - 'a'] = new Node();
                count++;
            }

            temp = temp->links[ch - 'a'];
        }
    }
};
int countDistinctSubstrings(string &s)
{
    Trie t;
    int n = s.length();
    int count = 0;

    // T.C -> O(n^2)
    for (int i = 0; i < n; i++) {
        string str = "";
        for (int j = i; j < n; j++) {
            str += s[j];

            t.insert(str, count);
        }
    }

    return count + 1;   // Add empty substring
}