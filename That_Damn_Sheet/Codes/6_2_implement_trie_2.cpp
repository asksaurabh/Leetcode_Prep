struct Node {
    Node* links[26];
    int endWord = 0;
    int countPrefix = 0;
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
            if (temp->links[ch - 'a'] == nullptr) {
                temp->links[ch - 'a'] = new Node();
            }

            temp = temp->links[ch - 'a'];
            temp->countPrefix++;            // There is a word that has prefix ch.
        }

        temp->endWord++;
    }

    int countWordsEqualTo(string &word) {
        // See the ending here.
        Node* temp = root;
        for (char ch : word) {
            if (temp->links[ch - 'a'] == nullptr)
                return 0;

            temp = temp->links[ch - 'a'];
        }

        return temp->endWord;
    }

    int countWordsStartingWith(string &word) {
        Node* temp = root;
        for (char ch : word) {
            if (temp->links[ch - 'a'] == nullptr)
                return 0;

            temp = temp->links[ch - 'a'];
        }

        return temp->countPrefix;
    }

    void erase(string &word) {
        // Reduce the counts here. Not actually deleting the links.
        // We are assuming that the word given to erase exists in the trie
        Node* temp = root;
        for (char ch : word) {
            temp = temp->links[ch - 'a'];
            temp->countPrefix--;
        }

        temp->endWord--;
    }
};
