struct TrieNode : public unordered_map<char, TrieNode*> {
    bool is_end = false;
    TrieNode() {}
};

class Trie {
public:
    TrieNode* root;

    Trie() {
        root = new TrieNode;
    }

    void insert(string word) {
        TrieNode* node = root;
        for (auto c : word) {
            if (!node->count(c)) {
                (*node)[c] = new TrieNode;
            }
            node = (*node)[c];
        }
        node->is_end = true;
    }

    bool prefix(string prefix) {
        TrieNode* node = root;
        for (auto c : prefix) {
            if (!node->count(c)) {
                return false;
            }
            node = (*node)[c];
        }
        return true;
    }

    bool find(string word) {
        TrieNode* node = root;
        for (auto c : word) {
            if (!node->count(c)) {
                return false;
            }
            node = (*node)[c];
        }
        return node->is_end;
    }
};